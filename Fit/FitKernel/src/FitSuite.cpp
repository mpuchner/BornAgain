// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FitKernel/src/FitSuite.cpp
//! @brief     Implements class FitSuite.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FitSuite.h"
#include "FitKernel.h"
#include "FitSuitePrintObserver.h"
#include "MinimizerFactory.h"
#include "IHistogram.h"

FitSuite::FitSuite()
    : m_kernel(new FitKernel(this))
{

}

void FitSuite::addSimulationAndRealData(const GISASSimulation &simulation,
                                        const OutputData<double> &real_data)
{
    m_kernel->addSimulationAndRealData(simulation, real_data);
}

void FitSuite::addSimulationAndRealData(const GISASSimulation &simulation,
                                        const IHistogram &real_data)
{
    boost::scoped_ptr<OutputData<double> > data(real_data.createOutputData());
    m_kernel->addSimulationAndRealData(simulation, *data);
}

void FitSuite::addFitParameter(const std::string &name, double value, const AttLimits &attlim,
                               double step)
{
    m_kernel->addFitParameter(name, value, attlim, step);
}

void FitSuite::setMinimizer(const std::string &minimizer_name, const std::string &algorithm_name,
                            const std::string &minimizer_options)
{
    IMinimizer *minimizer = MinimizerFactory::createMinimizer(minimizer_name, algorithm_name,
                                                              minimizer_options);
    m_kernel->setMinimizer(minimizer);
}

void FitSuite::setMinimizer(IMinimizer *minimizer)
{
    m_kernel->setMinimizer(minimizer);
}

IMinimizer *FitSuite::getMinimizer()
{
    return m_kernel->getMinimizer();
}

void FitSuite::initPrint(int print_every_nth)
{
    boost::shared_ptr<FitSuitePrintObserver > observer(new FitSuitePrintObserver(print_every_nth));
    attachObserver(observer);
}

void FitSuite::fixAllParameters()
{
    getFitParameters()->fixAll();
}

void FitSuite::releaseAllParameters()
{
    getFitParameters()->releaseAll();
}

void FitSuite::setParametersFixed(const std::vector<std::string> &pars, bool is_fixed)
{
    getFitParameters()->setParametersFixed(pars, is_fixed);
}

void FitSuite::runFit()
{
    m_kernel->runFit();
}

IHistogram *FitSuite::getRealData(size_t i_item) const
{
    return IHistogram::createHistogram(*m_kernel->getFitObjects()->getRealData(i_item));
}

IHistogram *FitSuite::getSimulationData(size_t i_item) const
{
    return IHistogram::createHistogram(*m_kernel->getFitObjects()->getSimulationData(i_item));
}

IHistogram *FitSuite::getChiSquaredMap(size_t i_item) const
{
    boost::scoped_ptr<OutputData<double> > data(m_kernel->getFitObjects()->getChiSquaredMap(i_item));
    return IHistogram::createHistogram(*data);
}

FitSuiteObjects *FitSuite::getFitObjects()
{
    return m_kernel->getFitObjects();
}

FitSuiteParameters *FitSuite::getFitParameters()
{
    return m_kernel->getFitParameters();
}

FitSuiteStrategies *FitSuite::getFitStrategies()
{
    return m_kernel->getFitStrategies();
}

bool FitSuite::isLastIteration() const
{
    return m_kernel->isLastIteration();
}

size_t FitSuite::getNumberOfIterations() const
{
    return m_kernel->getNCalls();
}

size_t FitSuite::getNStrategy() const
{
    return m_kernel->getNStrategy();
}

void FitSuite::printResults() const
{
    m_kernel->printResults();
}

double FitSuite::getChi2() const
{
    return m_kernel->getMinimizer()->getMinValue();
}


