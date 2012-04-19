#ifndef TESTDIFFUSESCATTERING_H
#define TESTDIFFUSESCATTERING_H
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   TestDiffuseScattering.h
//! @brief  Test of diffusse (incoherent) scattering from rough multilayer in DWBA.
//! @author James Bond <j.bond@fz-juelich.de>, Chuck Norris <c.norris@fz-juelich.de>
//! @date   01.04.2012

#include "IAlgorithm.h"


class TestDiffuseScattering : public IAlgorithm
{
public:
    TestDiffuseScattering();

    void execute();
};

#endif // TESTDIFFUSESCATTERING_H
