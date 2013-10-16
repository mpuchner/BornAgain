#ifndef FITSUITEPRINTOBSERVER_H
#define FITSUITEPRINTOBSERVER_H

#include "IObserver.h"
#include <boost/date_time/posix_time/posix_time.hpp>

//! Print fit progress at the end of each FitSuite's iteration
class BA_CORE_API_ FitSuitePrintObserver : public IObserver
{
public:
    FitSuitePrintObserver(int print_every_nth = 1);
    virtual ~FitSuitePrintObserver(){}

    void update(IObservable *subject);

private:
    int m_print_every_nth;
    boost::posix_time::ptime m_start_time;
    boost::posix_time::ptime m_last_call_time;
};

#endif // FITSUITEPRINTOBSERVER_H


