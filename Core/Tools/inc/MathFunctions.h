// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tools/inc/MathFunctions.h
//! @brief     Defines functions in namespace MathFunctions.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include "Types.h"
#include "Units.h"
#include "Numeric.h"

#include <cstdlib>
#include <vector>
#include <cmath>

//! Various mathematical functions.

namespace MathFunctions
{

// ************************************************************************** //
//  Various functions
// ************************************************************************** //

    BA_CORE_API_ double StandardNormal(double x);
    BA_CORE_API_ double Gaussian(double x, double average, double std_dev);
    BA_CORE_API_ double IntegratedGaussian(double x, double average, double std_dev);

//! Sine integral function: \f$Si(x)\equiv\int_0^x du \sin(u)/u\f$
    BA_CORE_API_ double Si(double x);

//! sinc function: \f$sinc(x)\equiv\sin(x)/x\f$
    BA_CORE_API_ double sinc(double x);

//! Complex sinc function: \f$sinc(x)\equiv\sin(x)/x\f$
    BA_CORE_API_ complex_t sinc(const complex_t z);

//! Complex tanhc function: \f$tanhc(x)\equiv\tanh(x)/x\f$
    BA_CORE_API_ complex_t tanhc(const complex_t z);

    BA_CORE_API_ complex_t Laue(const complex_t z, size_t N);


// ************************************************************************** //
//  Bessel functions
// ************************************************************************** //

//! Bessel function of the first kind and order 0
    BA_CORE_API_ double Bessel_J0(double x);

//! Bessel function of the first kind and order 1
    BA_CORE_API_ double Bessel_J1(double x);

//! Bessel function  Bessel_J1(x)/x
    BA_CORE_API_ double Bessel_J1c(double x);

//! Complex Bessel function of the first kind and order 0
    BA_CORE_API_ complex_t Bessel_J0(const complex_t z);

//! Complex Bessel function of the first kind and order 1
    BA_CORE_API_ complex_t Bessel_J1(const complex_t z);

//! Complex Bessel function  Bessel_J1(x)/x
    BA_CORE_API_ complex_t Bessel_J1c(const complex_t z);


// ************************************************************************** //
//  Fourier transform and convolution
// ************************************************************************** //

    enum EFFTDirection { FORWARD_FFT, BACKWARD_FFT };

    BA_CORE_API_ std::vector<complex_t >
        FastFourierTransform(const std::vector<complex_t > &data, EFFTDirection tcase);

    BA_CORE_API_ std::vector<complex_t >
        FastFourierTransform(const std::vector<double > &data, EFFTDirection tcase);

    BA_CORE_API_ std::vector<complex_t>
        ConvolveFFT(const std::vector<double> &signal, const std::vector<double> &resfunc);


// ************************************************************************** //
//  Random number generators
// ************************************************************************** //

    BA_CORE_API_ double GenerateUniformRandom();
    BA_CORE_API_ double GenerateStandardNormalRandom();
    BA_CORE_API_ double GenerateNormalRandom(double average, double std_dev);


// ************************************************************************** //
//  Workarounds for std functions
// ************************************************************************** //

    BA_CORE_API_ inline bool isnan(double x)
    {
#ifdef _MSC_VER
        return _isnan(x);
#else
        return std::isnan(x);
#endif
    }

    BA_CORE_API_ inline bool isinf(double x)
    {
#ifdef _MSC_VER
        return !_finite(x);
#else
        return std::isinf(x);
#endif
    }

} // Namespace MathFunctions


#endif // MATHFUNCTIONS_H
