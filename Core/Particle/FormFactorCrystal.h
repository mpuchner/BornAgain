// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Particle/FormFactorCrystal.h
//! @brief     Declares class FormFactorCrystal.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FORMFACTORCRYSTAL_H
#define FORMFACTORCRYSTAL_H

#include "IFormFactorBorn.h" // inheriting from
#include "Lattice.h"

//! @class FormFactorCrystal
//! @ingroup formfactors
//! @brief The formfactor of a MesoCrystal

class BA_CORE_API_ FormFactorCrystal : public IFormFactorBorn
{
public:
    FormFactorCrystal(const Lattice& lattice, const IFormFactor& basis_form_factor,
                      const IFormFactor& meso_form_factor);

    virtual ~FormFactorCrystal();

    FormFactorCrystal* clone() const;

    virtual void accept(ISampleVisitor* visitor) const final { visitor->visit(this); }

    virtual double getVolume() const final;

    virtual double getRadialExtension() const final;

    virtual complex_t evaluate(const WavevectorInfo& wavevectors) const final;

#ifndef SWIG
    virtual Eigen::Matrix2cd evaluatePol(const WavevectorInfo& wavevectors) const;
#endif

    virtual complex_t evaluate_for_q(const cvector_t q) const;

private:
    void calculateLargestReciprocalDistance();

    Lattice m_lattice;
    IFormFactor* mp_basis_form_factor;
    IFormFactor* mp_meso_form_factor; //!< The outer shape of this mesocrystal
    double m_max_rec_length;
};

#endif // FORMFACTORCRYSTAL_H
