//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Device/InputOutput/OutputDataReadFactory.h
//! @brief     Defines class OutputDataReadFactory.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_DEVICE_INPUTOUTPUT_OUTPUTDATAREADFACTORY_H
#define BORNAGAIN_DEVICE_INPUTOUTPUT_OUTPUTDATAREADFACTORY_H

#include "Device/InputOutput/OutputDataReader.h"

//! Creates reader appropariate for given type of files.
//! @ingroup input_output_internal

class OutputDataReadFactory {
public:
    static OutputDataReader* getReader(const std::string& file_name);
    static OutputDataReader* getReflectometryReader(const std::string& file_name);

private:
    static IOutputDataReadStrategy* getReadStrategy(const std::string& file_name);
};

#endif // BORNAGAIN_DEVICE_INPUTOUTPUT_OUTPUTDATAREADFACTORY_H
