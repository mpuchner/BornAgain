//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Wrap/w32pragma.h
//! @brief     Pragmas and defines for MSVC.
//!            Always included per cmake/BornAgain/Windows.cmake
//
//  ************************************************************************************************

/*************************************************************************
 * Copyright (C) 1995-2002, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef BORNAGAIN_WRAP_W32PRAGMA_H
#define BORNAGAIN_WRAP_W32PRAGMA_H

/*************************************************************************
 *                                                                       *
 * w32pragma                                                             *
 *                                                                       *
 * Pragmas and defines for MSVC                                          *
 *                                                                       *
 *************************************************************************/

#ifdef _WIN32

/* Disable warning about truncated symboles (usually coming from stl) */
#pragma warning(disable : 4786)
/* Disable warning about inconsistent dll linkage (dllexport assumed) */
#pragma warning(disable : 4273)
/* "no suitable definition provided for explicit template instantiation"*/
#pragma warning(disable : 4661)
/* "deprecated, use ISO C++ conformant name" */
#pragma warning(disable : 4996)
/* "new behavior: elements default initialized" */
#pragma warning(disable : 4351)
/* local static not thread safe */
#pragma warning(disable : 4640)
/*forcing int to bool (performance warning) */
#pragma warning(disable : 4800)
/* truncation from double to float */
#pragma warning(disable : 4305)
/* signed unsigned mismatch */
#pragma warning(disable : 4018)
/* truncation of constant value */
#pragma warning(disable : 4309)
/* check op precedence for error */
#pragma warning(disable : 4554)
/* qualifier applied to reference type; ignored */
#pragma warning(disable : 4181)
/* /GS can not buffer overrun protect parameters and locals: function not optimized */
#pragma warning(disable : 4748)
/* function(): resolved overload was found by argument-dependent lookup */
#pragma warning(disable : 4675)
/* X needs to have dll-interface to be used by clients of class Y */
#pragma warning(disable : 4251)
/* decorated name length exceeded, name was truncated */
#pragma warning(disable : 4503)

/* function is hidden */
#pragma warning(3 : 4266)
/* loop control variable is used outside the for-loop scope */
#pragma warning(3 : 4289)

/* no override available for virtual member function from base */
#pragma warning(disable : 4266)

#endif // _WIN32

#endif // BORNAGAIN_WRAP_W32PRAGMA_H
