#include "FunctionalTestAssembler.h"
#include "AdvancedFunctionalTest.h"
#include "SimulationRegistry.h"
#include "SampleBuilderFactory.h"
#include "FileSystem.h"
#include "IntensityDataIOFactory.h"
#include "FunctionalTestComponentService.h"
#include <boost/scoped_ptr.hpp>
#include <iostream>

AdvancedFunctionalTestRegistry FunctionalTestAssembler::m_catalogue = AdvancedFunctionalTestRegistry();

IAdvancedFunctionalTest *FunctionalTestAssembler::getTest(const std::string &test_name)
{
    AdvancedFunctionalTestInfo info = m_catalogue.getTestInfo(test_name);


//    SimulationRegistry sim_registry;
//    GISASSimulation *simulation = sim_registry.createSimulation(info.m_simulation_name);
//    assert(simulation);

//    SampleBuilderFactory sample_factory;
//    SampleBuilder_t builder = sample_factory.createBuilder(info.m_sample_builder_name);

//    simulation->setSampleBuilder(builder);

//    std::string filename = Utils::FileSystem::GetReferenceDataDir() + "isgisaxs01_reference.int.gz";
//    OutputData<double> *reference = IntensityDataIOFactory::readIntensityData(filename);

//    return new AdvancedFunctionalTest(test_name, simulation, reference, info.m_threshold);

//    FunctionalTestComponentService *service = new FunctionalTestComponentService(info.m_simulation_name, info.m_sample_builder_name, info.m_component_registry_name);
    FunctionalTestComponentService *service = new FunctionalTestComponentService(info);
    return new AdvancedFunctionalMultiTest(test_name, info.m_test_description, service);

}

bool FunctionalTestAssembler::isValidTest(const std::string &test_name)
{
    return m_catalogue.find(test_name) != m_catalogue.end();
}

void FunctionalTestAssembler::printCatalogue() const
{
    m_catalogue.printCatalogue(std::cout);
}

int ADVANCED_FUNCTIONAL_TEST(const std::string &test_name)
{
    FunctionalTestAssembler assembler;
    if(!assembler.isValidTest(test_name)) {
        std::cout << "FUNCTIONAL_TEST() -> Non existing test with name '" << test_name << "', "
                  << "use argument from the list of defined tests" << std::endl;
        assembler.printCatalogue();
        return 1;
    }

    boost::scoped_ptr<IAdvancedFunctionalTest> test(assembler.getTest(test_name));
    test->runTest();
    return test->analyseResults();
}



