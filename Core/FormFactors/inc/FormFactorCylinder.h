#ifndef FORMFACTORCYLINDER_H
#define FORMFACTORCYLINDER_H
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   FormFactorCylinder.h
//! @brief  Definition of FormFactorCylinder
//! @author Scientific Computing Group at FRM II
//! @date   01.05.2012

#include "IFormFactorBorn.h"
#include "IStochasticParameter.h"


class FormFactorCylinder : public IFormFactorBorn
{
public:
    FormFactorCylinder(double height, double radius);
//    FormFactorCylinder(StochasticParameter<double> *p_height, StochasticParameter<double> *p_radius);
    ~FormFactorCylinder();
    virtual FormFactorCylinder *clone() const;

    virtual int getNumberOfStochasticParameters() const { return 2; }

    virtual double getHeight() const { return m_height; }

    virtual complex_t evaluate_for_q(const cvector_t &q) const;



private:
    FormFactorCylinder(const FormFactorCylinder &);
    FormFactorCylinder &operator=(const FormFactorCylinder &);

    //! initialize pool parameters, i.e. register some of class members for later access via parameter pool
    virtual void init_parameters();

//    //! print class
//    void print(std::ostream &ostr) const;

//    StochasticParameter<double> *mp_height;
//    StochasticParameter<double> *mp_radius;
    double m_height;
    double m_radius;
};

#endif // FORMFACTORCYLINDER_H
