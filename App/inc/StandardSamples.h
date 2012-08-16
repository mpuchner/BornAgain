#ifndef STANDARDSAMPLES_H
#define STANDARDSAMPLES_H

#include "ISample.h"
#include "SampleFactory.h"


namespace StandardSamples{

ISample *AirOnSubstrate();
ISample *SubstrateOnSubstrate();
ISample *SimpleMultilayer();
ISample *MultilayerOffspecTestcase1a();
ISample *MultilayerOffspecTestcase1b();
ISample *MultilayerOffspecTestcase2a();
ISample *MultilayerOffspecTestcase2b();
ISample *IsGISAXS1_CylinderAndPrism();
ISample *IsGISAXS3_CylinderDWBA();
ISample *IsGISAXS3_CylinderBA();
ISample *IsGISAXS3_CylinderBASize();
ISample *IsGISAXS9_Pyramid();
ISample *IsGISAXS9_RotatedPyramid();
ISample *IsGISAXS10_CylindersParacrystal1D();
ISample *MesoCrystal1();

}



#endif // STANDARDSAMPLES_H
