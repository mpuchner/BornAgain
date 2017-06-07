// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/TestMachinery/IStandardTest.cpp
//! @brief     Implements class IStandardTest.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "IStandardTest.h"
#include "StandardSimulationsRegistry.h"
#include "GISASSimulation.h"
#include "IFunctionalTest.h"
#include "SampleBuilderFactory.h"
#include "SimulationFactory.h"
#include "SubtestRegistry.h"

// ************************************************************************** //
//  Test execution
// ************************************************************************** //

//! Runs test (name given as command-line argument), and returns true when successful

bool IStandardTest::execute(int argc, char** argv) {
    // parse command-line arguments and retrieve test info from registry
    std::string test_name;
    if(argc > 1)
        test_name = std::string(argv[1]);
    m_info = StandardSimulationsRegistry::instance().getItemOrExplain(test_name, getName());
    if( !m_info )
        throw Exceptions::RuntimeErrorException("IStandardTest -> Error in look up.");

    if (m_info->m_subtest_type == "None")
        return execute_onetest();
    else
        return execute_subtests();
}

//! Runs a single test, and returns true when successful

bool IStandardTest::execute_onetest()
{
    setName( m_info->m_test_name );
    return getTest()->runTest();
}

//! Runs all available subtests, and returns true if all succeed

bool IStandardTest::execute_subtests()
{
    // initialize subtest registry
    std::vector<std::string> subtest_names;
    ISubtestRegistry* subtest_registry;
    if       (m_info->m_subtest_type == "FormFactors") {
        subtest_registry = new SubtestRegistryFormFactor;
    } else if(m_info->m_subtest_type == "FTDistributions2D") {
        subtest_registry = new SubtestRegistryFTDistribution2D;
    } else
        throw Exceptions::RuntimeErrorException("IStandardTest -> Error. "
                                    "Unknown factory '"+m_info->m_subtest_type+"'.");
    subtest_names = subtest_registry->keys();
    size_t n_subtests = subtest_names.size();

    // run and analyze subtests
    int number_of_failed_tests = 0;
    for (size_t i = 0; i < n_subtests; ++i) {
        setName( m_info->m_test_name + "_" + subtest_names[i] );
        m_subtest_item = subtest_registry->getItem(subtest_names[i]);
        std::cout << "IStandardTest::execute() -> " << getName()
                  << " " << i+1 << "/" << n_subtests << " (" << subtest_names[i] << ")\n";
        if(!getTest()->runTest())
            ++number_of_failed_tests;
    }
    delete subtest_registry;

    // report overall result
    std::cout << "summary: " << number_of_failed_tests << " of " << n_subtests <<
        " subtests failed\n";
    return number_of_failed_tests==0;
}

// ************************************************************************** //
//  Functions called by getTest() in *Suite.cpp
// ************************************************************************** //

std::string IStandardTest::getTestDescription() const { return m_info->m_test_description; }

double IStandardTest::getTestThreshold() const { return m_info->m_threshold; }

GISASSimulation* IStandardTest::getSimulation() const
{
    std::shared_ptr<IMultiLayerBuilder> sample_builder(
        SampleBuilderFactory().createItem(m_info->m_sample_builder_name) );
    if(m_subtest_item)
        sample_builder->set_subtest(m_subtest_item);

    GISASSimulation* result = SimulationFactory().createItem(m_info->m_simulation_name);
    result->setSampleBuilder(sample_builder);
    return result;
}