#include "TestIsGISAXS11.h"
#include "IsGISAXSTools.h"
#include "Units.h"
#include "Utils.h"
#include "GISASExperiment.h"
#include "MultiLayer.h"
#include "SampleFactory.h"
#include "DrawHelper.h"

#include "TCanvas.h"

void TestIsGISAXS11::execute()
{
    MultiLayer *sample = dynamic_cast<MultiLayer *>(SampleFactory::instance().createItem("IsGISAXS11_CoreShellParticle"));

    GISASExperiment experiment(mp_options);
    experiment.setSample(*sample);
    experiment.setDetectorParameters(100, 0.0*Units::degree, 2.0*Units::degree, 100, 0.0*Units::degree, 2.0*Units::degree, true);
    experiment.setBeamParameters(1.0*Units::angstrom, -0.2*Units::degree, 0.0*Units::degree);
    experiment.runSimulation();
    OutputData<double > *mp_intensity_output = experiment.getOutputDataClone();
    IsGISAXSTools::writeOutputDataToFile(*mp_intensity_output, Utils::FileSystem::GetHomePath()+"./Examples/IsGISAXS_examples/ex-11/this_core_shell_qxqy.ima");
}

void TestIsGISAXS11::finalise()
{
    std::string isgi_file(Utils::FileSystem::GetHomePath()+"./Examples/IsGISAXS_examples/ex-11/isgi_core_shell_qxqy.ima");
    std::string this_file(Utils::FileSystem::GetHomePath()+"./Examples/IsGISAXS_examples/ex-11/this_core_shell_qxqy.ima");

    OutputData<double> *isgi_data = IsGISAXSTools::readOutputDataFromFile(isgi_file);
    OutputData<double> *our_data = IsGISAXSTools::readOutputDataFromFile(this_file);

    TCanvas *c1 = DrawHelper::instance().createAndRegisterCanvas("TestIsGISAXS11_c1", "Core shell parallelepiped islands");
    c1->Divide(2,2);

    IsGISAXSTools::setMinimum(1.);
    // our calculations
    c1->cd(1); gPad->SetLogz();
    IsGISAXSTools::drawOutputDataInPad(*our_data, "CONT4 Z", "Our core shell particles");

    // isgisaxs data
    c1->cd(2); gPad->SetLogz();
    IsGISAXSTools::drawOutputDataInPad(*isgi_data, "CONT4 Z", "IsGisaxs core shell particles");

    // difference
    c1->cd(3);
    IsGISAXSTools::setMinimum(-0.0001);
    IsGISAXSTools::setMaximum(0.0001);
    IsGISAXSTools::drawOutputDataDifference2D(*our_data, *isgi_data, "CONT4 Z", "2D Difference map");

    // difference
    c1->cd(4);
    IsGISAXSTools::resetMinimumAndMaximum();
    IsGISAXSTools::setMinimum(1);
    IsGISAXSTools::drawOutputDataDifference1D(*our_data, *isgi_data, "", "Difference spectra");

    delete isgi_data;
    delete our_data;}