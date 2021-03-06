//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/StandardSamples/CustomMorphologyBuilder.h
//! @brief     Defines class CustomMorphologyBuilder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_SAMPLE_STANDARDSAMPLES_CUSTOMMORPHOLOGYBUILDER_H
#define BORNAGAIN_SAMPLE_STANDARDSAMPLES_CUSTOMMORPHOLOGYBUILDER_H

#include "Sample/SampleBuilderEngine/ISampleBuilder.h"

//! Builds sample: mixture of different particles (IsGISAXS example #7).
//! @ingroup standard_samples

class CustomMorphologyBuilder : public ISampleBuilder {
public:
    MultiLayer* buildSample() const;
};

#endif // BORNAGAIN_SAMPLE_STANDARDSAMPLES_CUSTOMMORPHOLOGYBUILDER_H
