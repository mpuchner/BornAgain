// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/Scattering/FormFactorBAPol.cpp
//! @brief     Defines class FormFactorBAPol.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Sample/Scattering/FormFactorBAPol.h"
#include "Sample/Material/WavevectorInfo.h"
#include <stdexcept>

FormFactorBAPol::FormFactorBAPol(const IFormFactor& ff) : m_ff(ff.clone())
{
    setName("FormFactorBAPol");
}

FormFactorBAPol::~FormFactorBAPol() = default;

FormFactorBAPol* FormFactorBAPol::clone() const
{
    return new FormFactorBAPol(*m_ff);
}

complex_t FormFactorBAPol::evaluate(const WavevectorInfo&) const
{
    throw std::runtime_error("FormFactorBAPol::evaluate: "
                             "should never be called for matrix interactions");
}

Eigen::Matrix2cd FormFactorBAPol::evaluatePol(const WavevectorInfo& wavevectors) const
{
    Eigen::Matrix2cd ff_BA = m_ff->evaluatePol(wavevectors);
    Eigen::Matrix2cd result;
    result(0, 0) = -ff_BA(1, 0);
    result(0, 1) = ff_BA(0, 0);
    result(1, 0) = -ff_BA(1, 1);
    result(1, 1) = ff_BA(0, 1);
    return result;
}

void FormFactorBAPol::setAmbientMaterial(const Material& material)
{
    m_ff->setAmbientMaterial(material);
}

double FormFactorBAPol::volume() const
{
    return m_ff->volume();
}

double FormFactorBAPol::radialExtension() const
{
    return m_ff->radialExtension();
}

double FormFactorBAPol::bottomZ(const IRotation& rotation) const
{
    return m_ff->bottomZ(rotation);
}

double FormFactorBAPol::topZ(const IRotation& rotation) const
{
    return m_ff->topZ(rotation);
}
