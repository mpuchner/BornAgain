// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/Slice/SpecularSimulationElement.h
//! @brief     Declares the class SpecularSimulationElement.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_MULTILAYER_SPECULARSIMULATIONELEMENT_H
#define BORNAGAIN_CORE_MULTILAYER_SPECULARSIMULATIONELEMENT_H

#include "Base/Pixel/PolarizationHandler.h"
#include "Base/Types/Complex.h"
#include "Base/Vector/Vectors3D.h"
#include <memory>
#include <vector>

class Slice;

//! Data stucture containing both input and output of a single image pixel for specular simulation.
//! @ingroup simulation

class SpecularSimulationElement
{
public:
    SpecularSimulationElement(double kz, bool computable);
    SpecularSimulationElement(double wavelength, double alpha, bool computable);

    SpecularSimulationElement(const SpecularSimulationElement& other);
    SpecularSimulationElement(SpecularSimulationElement&& other) noexcept;

    ~SpecularSimulationElement();

    SpecularSimulationElement& operator=(const SpecularSimulationElement& other);

    //! Assigns PolarizationHandler.
    void setPolarizationHandler(const PolarizationHandler& handler);

    //! Returns assigned PolarizationHandler.
    const PolarizationHandler& polarizationHandler() const { return m_polarization; }

    double getIntensity() const { return m_intensity; }
    void setIntensity(double intensity) { m_intensity = intensity; }

    //! Returns calculation flag (if it's false, zero intensity is assigned to the element)
    bool isCalculated() const { return m_computable; }

    //! Returns kz values for Abeles computation of reflection/transition coefficients
    std::vector<complex_t> produceKz(const std::vector<Slice>& slices);

private:
    void swapContent(SpecularSimulationElement& other);

    PolarizationHandler m_polarization;
    double m_intensity; //!< simulated intensity for detector cell
    const bool m_computable;
    std::function<std::vector<complex_t>(const std::vector<Slice>&)> m_kz_computation;
};

#endif // BORNAGAIN_CORE_MULTILAYER_SPECULARSIMULATIONELEMENT_H
