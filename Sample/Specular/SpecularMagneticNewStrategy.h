//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/Specular/SpecularMagneticNewStrategy.h
//! @brief     Defines class SpecularMagneticNewStrategy.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_SAMPLE_SPECULAR_SPECULARMAGNETICNEWSTRATEGY_H
#define BORNAGAIN_SAMPLE_SPECULAR_SPECULARMAGNETICNEWSTRATEGY_H

#include "Sample/RT/MatrixRTCoefficients_v3.h"
#include "Sample/Specular/ISpecularStrategy.h"
#include <memory>
#include <vector>

class Slice;

//! Implements the magnetic Fresnel computation with Nevot-Croce roughness
//!
//! Implements the transfer matrix formalism for the calculation of wave
//! amplitudes of the coherent wave solution in a multilayer with magnetization.
//! For a description, see internal
//! document "Polarized Implementation of the Transfer Matrix Method"
//!
//! @ingroup algorithms_internal
class SpecularMagneticNewStrategy : public ISpecularStrategy {
public:
    //! Computes refraction angle reflection/transmission coefficients
    //! for given sliced multilayer and wavevector k
    ISpecularStrategy::coeffs_t Execute(const std::vector<Slice>& slices, const kvector_t& k) const;

    //! Computes refraction angle reflection/transmission coefficients
    //! for given sliced multilayer and a set of kz projections corresponding to each slice
    ISpecularStrategy::coeffs_t Execute(const std::vector<Slice>& slices,
                                        const std::vector<complex_t>& kz) const;

private:
    std::vector<MatrixRTCoefficients_v3> computeTR(const std::vector<Slice>& slices,
                                                   const std::vector<complex_t>& kzs) const;

    virtual std::pair<Eigen::Matrix2cd, Eigen::Matrix2cd>
    computeBackwardsSubmatrices(const MatrixRTCoefficients_v3& coeff_i,
                                const MatrixRTCoefficients_v3& coeff_i1, double sigma) const = 0;

    void calculateUpwards(std::vector<MatrixRTCoefficients_v3>& coeff,
                          const std::vector<Slice>& slices) const;
};

#endif // BORNAGAIN_SAMPLE_SPECULAR_SPECULARMAGNETICNEWSTRATEGY_H
