//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Device/Instrument/PyArrayImportUtils.cpp
//! @brief     Implements functions in namespace PyArrayImport
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "Device/Instrument/PyArrayImportUtils.h"
#include "Device/Intensity/ArrayUtils.h"

OutputData<double>* PyArrayImport::importArrayToOutputData(const std::vector<double>& vec) {
    return ArrayUtils::createData(vec).release();
}

OutputData<double>*
PyArrayImport::importArrayToOutputData(const std::vector<std::vector<double>>& vec) {
    return ArrayUtils::createData(vec).release();
}
