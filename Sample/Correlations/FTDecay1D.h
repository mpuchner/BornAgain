//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/Correlations/FTDecay1D.h
//! @brief     Defines classes IFTDecayFunction1D, IFTDecayFunction2D,
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_SAMPLE_CORRELATIONS_FTDECAY1D_H
#define BORNAGAIN_SAMPLE_CORRELATIONS_FTDECAY1D_H

#include "Base/Math/Constants.h"
#include "Base/Types/ICloneable.h"
#include "Param/Node/INode.h"
#include <utility>

//! Interface for a one-dimensional decay function,
//!   with evaluate(q) returning the Fourier transform,
//!   normalized to \f$\int dq\; {\rm evaluate}(q) = 1\f$.
//! @ingroup distribution_internal
class IFTDecayFunction1D : public ICloneable, public INode {
public:
    IFTDecayFunction1D(const NodeMeta& meta, const std::vector<double>& PValues);

    virtual IFTDecayFunction1D* clone() const = 0;
    virtual double evaluate(double q) const = 0;
    double decayLength() const { return m_decay_length; }

protected:
    const double& m_decay_length;
};

//! One-dimensional Cauchy decay function in reciprocal space;
//! corresponds to exp(-|x|/decay_length) in real space.
//! @ingroup decayFT
class FTDecayFunction1DCauchy : public IFTDecayFunction1D {
public:
    FTDecayFunction1DCauchy(const std::vector<double> P);
    FTDecayFunction1DCauchy(double decay_length);

    FTDecayFunction1DCauchy* clone() const;
    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }
    double evaluate(double q) const final;
};

//! One-dimensional Gauss decay function in reciprocal space;
//! corresponds to exp[-x^2/(2*decay_length^2)] in real space.
//! @ingroup decayFT
class FTDecayFunction1DGauss : public IFTDecayFunction1D {
public:
    FTDecayFunction1DGauss(const std::vector<double> P);
    FTDecayFunction1DGauss(double decay_length);

    FTDecayFunction1DGauss* clone() const;
    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }
    double evaluate(double q) const final;
};

//! One-dimensional triangle decay function in reciprocal space;
//! corresponds to 1-|x|/decay_length if |x|<decay_length (and 0 otherwise) in real space.
//! @ingroup decayFT
class FTDecayFunction1DTriangle : public IFTDecayFunction1D {
public:
    FTDecayFunction1DTriangle(const std::vector<double> P);
    FTDecayFunction1DTriangle(double decay_length);

    FTDecayFunction1DTriangle* clone() const;
    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }
    double evaluate(double q) const final;
};

//! One-dimensional pseudo-Voigt decay function in reciprocal space;
//! corresponds to eta*Gauss + (1-eta)*Cauchy.
//! @ingroup decayFT
class FTDecayFunction1DVoigt : public IFTDecayFunction1D {
public:
    FTDecayFunction1DVoigt(const std::vector<double> P);
    FTDecayFunction1DVoigt(double decay_length, double eta);

    FTDecayFunction1DVoigt* clone() const;
    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }
    double evaluate(double q) const final;
    double eEta() const { return m_eta; }

private:
    const double& m_eta;
};

#endif // BORNAGAIN_SAMPLE_CORRELATIONS_FTDECAY1D_H
