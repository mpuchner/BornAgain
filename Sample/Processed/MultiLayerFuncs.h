//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/Processed/MultiLayerFuncs.h
//! @brief     Global functions related to MultiLayers.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_SAMPLE_PROCESSED_MULTILAYERFUNCS_H
#define BORNAGAIN_SAMPLE_PROCESSED_MULTILAYERFUNCS_H

#include "Base/Types/Complex.h"
#include <utility>
#include <vector>

class MultiLayer;

//! @ingroup materials

//! Calculate average material profile for given multilayer
std::vector<complex_t> materialProfileSLD(const MultiLayer& multilayer, int n_points, double z_min,
                                          double z_max);

//! Get default z limits for generating a material profile
std::pair<double, double> defaultMaterialProfileLimits(const MultiLayer& multilayer);

//! Generate z values (equidistant) for use in materialProfileSLD
std::vector<double> generateZValues(int n_points, double z_min, double z_max);

#endif // BORNAGAIN_SAMPLE_PROCESSED_MULTILAYERFUNCS_H
