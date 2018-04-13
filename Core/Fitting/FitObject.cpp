// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Fitting/FitObject.cpp
//! @brief     Implements class FitObject.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "FitObject.h"
#include "BornAgainNamespace.h"
#include "DetectorFunctions.h"
#include "FitElement.h"
#include "IHistogram.h"
#include "IIntensityNormalizer.h"
#include "Simulation.h"
#include "SimulationArea.h"

static_assert(std::is_copy_constructible<FitObject>::value == false,
              "FitObject should not be copy constructable");
static_assert(std::is_copy_assignable<FitObject>::value == false,
              "FitObject should not be copy assignable");

FitObject::FitObject(const Simulation& simulation, const OutputData<double>& real_data,
                     double weight)
    : m_simulation(simulation.clone()), m_weight(weight), m_fit_elements_count(0)

{
    setName("FitObject");
    m_fit_elements_count = m_simulation->numberOfSimulationElements();
    registerChild(m_simulation.get());
    init_dataset(real_data);
}

FitObject::~FitObject() {}

const OutputData<double>& FitObject::realData() const { return *m_real_data.get(); }

const OutputData<double>& FitObject::simulationData() const { return *m_simulation_data.get(); }

std::vector<const INode*> FitObject::getChildren() const
{
    return std::vector<const INode*>() << m_simulation;
}

std::unique_ptr<IHistogram> FitObject::createRealDataHistogram() const
{
    OutputData<double> buff;
    buff.copyShapeFrom(simulationData());

    m_simulation->getInstrument().getDetector()->iterate([&](IDetector::const_iterator it){
        // FIXME find elegant (issue #2018)
        size_t rdata_index
            = m_simulation_data->getAllocatedSize() == m_real_data->getAllocatedSize()
                  ? it.roiIndex()
                  : it.detectorIndex();
        if (rdata_index >= m_real_data->getAllocatedSize())
            throw ("FitObject::prepareFitElements() -> Error. Out-of-bounds.");
        buff[it.roiIndex()] = (*m_real_data)[rdata_index];
    });

    return std::unique_ptr<IHistogram>(IHistogram::createHistogram(buff));
}

//! Check if real_data shape corresponds with the detector.

void FitObject::init_dataset(const OutputData<double>& real_data)
{
    const IDetector* detector = m_simulation->getInstrument().getDetector();
    if (!DetectorFunctions::hasSameDimensions(*detector, real_data)) {
        std::ostringstream message;
        message << "FitObject::check_realdata() -> Warning. Axes of the real data doesn't match "
                << "the detector. Real data:" << DetectorFunctions::axesToString(real_data)
                << ", detector:" << DetectorFunctions::axesToString(*detector) << ".";
        // FIXME find elegant way (issue #2018)
    }
    m_real_data.reset(real_data.clone());
}

size_t FitObject::numberOfFitElements() const { return m_fit_elements_count; }

//! Runs simulation and put results (the real and simulated intensities) into external vector.
//! Masked channels will be excluded from the vector.

void FitObject::prepareFitElements(std::vector<FitElement>& fit_elements, double weight,
                                   IIntensityNormalizer* normalizer)
{
    m_simulation->runSimulation();
    auto sim_result = m_simulation->result();
    m_simulation_data.reset(sim_result.data());

    if (normalizer)
        normalizer->apply(*m_simulation_data.get());

    m_simulation->getInstrument().getDetector()->iterate([&](IDetector::const_iterator it){
        // FIXME find elegant way (issue #2018)
        size_t rdata_index
            = m_simulation_data->getAllocatedSize() == m_real_data->getAllocatedSize()
                  ? it.roiIndex()
                  : it.detectorIndex();

        if (rdata_index >= m_real_data->getAllocatedSize())
            throw ("FitObject::prepareFitElements() -> Error. Out-of-bounds.");
        FitElement element(it.roiIndex(), (*m_simulation_data)[it.roiIndex()],
                           (*m_real_data)[rdata_index], weight);
        fit_elements.push_back(element);
    });
}
