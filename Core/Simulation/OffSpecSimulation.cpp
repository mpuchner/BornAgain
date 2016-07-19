// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Simulation/OffSpecSimulation.cpp
//! @brief     Implements class OffSpecSimulation.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "OffSpecSimulation.h"
#include "BornAgainNamespace.h"
#include "Histogram2D.h"
#include "ISample.h"
#include "SimulationElement.h"

OffSpecSimulation::OffSpecSimulation()
    : mp_alpha_i_axis(0)
{
    initialize();
}

OffSpecSimulation::OffSpecSimulation(const ISample& p_sample)
    : Simulation(p_sample)
    , mp_alpha_i_axis(0)
{
    initialize();
}

OffSpecSimulation::OffSpecSimulation(std::shared_ptr<ISampleBuilder> p_sample_builder)
    : Simulation(p_sample_builder)
    , mp_alpha_i_axis(0)
{
    initialize();
}

void OffSpecSimulation::prepareSimulation()
{
    checkInitialization();
    Simulation::prepareSimulation();
}

int OffSpecSimulation::getNumberOfSimulationElements() const
{
    checkInitialization();
    const IAxis &phi_axis = m_instrument.getDetectorAxis(0);
    const IAxis &alpha_axis = m_instrument.getDetectorAxis(1);
    return phi_axis.getSize()*alpha_axis.getSize()*mp_alpha_i_axis->getSize();
}

Histogram2D *OffSpecSimulation::getIntensityData() const
{
    const std::unique_ptr<OutputData<double> > data(getDetectorIntensity());
    return new Histogram2D(*data);
}

void OffSpecSimulation::setInstrument(const Instrument& instrument)
{
    m_instrument = instrument;
    updateIntensityMap();
}

void OffSpecSimulation::setBeamParameters(
        double lambda, const IAxis &alpha_axis, double phi_i) {
    delete mp_alpha_i_axis;
    mp_alpha_i_axis = alpha_axis.clone();
    if (alpha_axis.getSize()<1)
        throw Exceptions::ClassInitializationException(
                "OffSpecSimulation::prepareSimulation() "
                "-> Error. Incoming alpha range size < 1.");
    double alpha_start = alpha_axis[0];
    m_instrument.setBeamParameters(lambda, alpha_start, phi_i);
    updateIntensityMap();
}

void OffSpecSimulation::setBeamIntensity(double intensity)
{
    m_instrument.setBeamIntensity(intensity);
}

void OffSpecSimulation::setBeamPolarization(const kvector_t bloch_vector)
{
    m_instrument.setBeamPolarization(bloch_vector);
}

void OffSpecSimulation::setDetectorParameters(const OutputData<double>& output_data)
{
    m_instrument.matchDetectorAxes(output_data);
    updateIntensityMap();
}

void OffSpecSimulation::setDetectorParameters(size_t n_x, double x_min, double x_max,
                                              size_t n_y, double y_min, double y_max)
{
    m_instrument.setDetectorParameters(n_x, x_min, x_max, n_y, y_min, y_max);
    updateIntensityMap();
}

void OffSpecSimulation::setDetectorResolutionFunction(
        const IResolutionFunction2D &resolution_function)
{
    m_instrument.setDetectorResolutionFunction(resolution_function);
}

void OffSpecSimulation::removeDetectorResolutionFunction()
{
    m_instrument.setDetectorResolutionFunction(0);
}

void OffSpecSimulation::setAnalyzerProperties(
    const kvector_t direction, double efficiency, double total_transmission)
{
    m_instrument.setAnalyzerProperties(direction, efficiency, total_transmission);
}

std::string OffSpecSimulation::addParametersToExternalPool(std::string path,
        ParameterPool* external_pool, int copy_number) const
{
    // add own parameters
    std::string new_path = IParameterized::addParametersToExternalPool(
            path, external_pool, copy_number);

    // add parameters of the instrument
    m_instrument.addParametersToExternalPool(new_path, external_pool, -1);

    if (mp_sample_builder.get()) {
       // add parameters of the sample builder
        mp_sample_builder->addParametersToExternalPool(
            new_path, external_pool, -1);
    } else if (mP_sample.get()) {
        // add parameters of the existing sample
        mP_sample->addParametersToExternalPool(new_path, external_pool, -1);
    }

    return new_path;
}

// *** protected ***

OffSpecSimulation::OffSpecSimulation(const OffSpecSimulation& other)
    : Simulation(other)
    , m_instrument(other.m_instrument)
    , mp_alpha_i_axis(0)
    , m_intensity_map()
{
    if(other.mp_alpha_i_axis) mp_alpha_i_axis = other.mp_alpha_i_axis->clone();
    m_intensity_map.copyFrom(other.m_intensity_map);

    initialize();
}

void OffSpecSimulation::initSimulationElementVector()
{
    m_sim_elements.clear();
    Beam beam = m_instrument.getBeam();
    double wavelength = beam.getWavelength();
    double phi_i = beam.getPhi();
    checkInitialization();

    for (size_t alpha_i_index = 0; alpha_i_index < mp_alpha_i_axis->getSize(); ++alpha_i_index) {
        // Incoming angle by convention defined as positive:
        double alpha_i = mp_alpha_i_axis->getBin(alpha_i_index).getMidPoint();
        beam.setCentralK(wavelength, alpha_i, phi_i);
        m_instrument.setBeam(beam);
        std::vector<SimulationElement> sim_elements_alpha_i =
            m_instrument.createSimulationElements();
        m_sim_elements.insert(m_sim_elements.end(), sim_elements_alpha_i.begin(),
                              sim_elements_alpha_i.end());
    }
}

void OffSpecSimulation::transferResultsToIntensityMap()
{
    checkInitialization();
    updateIntensityMap();
    const IAxis &phi_axis = m_instrument.getDetectorAxis(0);
    size_t phi_f_size = phi_axis.getSize();
    if (phi_f_size*m_intensity_map.getAllocatedSize()!=m_sim_elements.size()) {
        throw Exceptions::RuntimeErrorException("OffSpecSimulation::transferResultsToIntensityMap: "
                                    "intensity map size does not conform to number of "
                                    "calculated intensities");
    }
    for (size_t i=0; i<mp_alpha_i_axis->getSize(); ++i)
        transferDetectorImage(i);
}

double OffSpecSimulation::getBeamIntensity() const
{
    return m_instrument.getBeamIntensity();
}

void OffSpecSimulation::updateIntensityMap()
{
    m_intensity_map.clear();
    if (mp_alpha_i_axis)
        m_intensity_map.addAxis(*mp_alpha_i_axis);
    size_t detector_dimension = m_instrument.getDetectorDimension();
    if (detector_dimension==2)
        m_intensity_map.addAxis(m_instrument.getDetectorAxis(1));
    m_intensity_map.setAllTo(0.);
}

void OffSpecSimulation::transferDetectorImage(int index)
{
    OutputData<double> detector_image;
    size_t detector_dimension = m_instrument.getDetectorDimension();
    for (size_t dim=0; dim<detector_dimension; ++dim)
        detector_image.addAxis(m_instrument.getDetectorAxis(dim));
    size_t detector_size = detector_image.getAllocatedSize();
    for (size_t i=0; i<detector_size; ++i)
        detector_image[i] = m_sim_elements[index*detector_size + i].getIntensity();
    m_instrument.applyDetectorResolution(&detector_image);
    size_t y_axis_size = m_instrument.getDetectorAxis(1).getSize();
    for (size_t i=0; i<detector_size; ++i) {
        m_intensity_map[index*y_axis_size + i%y_axis_size] += detector_image[i];
    }
}

void OffSpecSimulation::checkInitialization() const
{
    if (!mp_alpha_i_axis || mp_alpha_i_axis->getSize()<1) {
        throw Exceptions::ClassInitializationException(
                "OffSpecSimulation::checkInitialization() "
                "Incoming alpha range not configured.");
    }
    if (m_instrument.getDetectorDimension()!=2)
        throw Exceptions::RuntimeErrorException(
            "OffSpecSimulation::checkInitialization: detector is not two-dimensional");
    const IAxis &phi_axis = m_instrument.getDetectorAxis(0);
    if (phi_axis.getName()!=BornAgain::PHI_AXIS_NAME)
        throw Exceptions::RuntimeErrorException(
            "OffSpecSimulation::checkInitialization: phi-axis is not correct");
    const IAxis &alpha_axis = m_instrument.getDetectorAxis(1);
    if (alpha_axis.getName()!=BornAgain::ALPHA_AXIS_NAME)
        throw Exceptions::RuntimeErrorException(
            "OffSpecSimulation::checkInitialization: alpha-axis is not correct");
}

void OffSpecSimulation::initialize()
{
    setName(BornAgain::OffSpecSimulationType);
    init_parameters();
}
