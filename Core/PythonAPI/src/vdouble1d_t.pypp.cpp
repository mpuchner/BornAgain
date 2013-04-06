// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence 
//! @brief automatically generated boost::python code for PythonCoreAPI  

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "PythonCoreList.h"
#include "vdouble1d_t.pypp.h"

namespace bp = boost::python;

void register_vdouble1d_t_class(){

    { //::std::vector< double >
        typedef bp::class_< std::vector< double > > vdouble1d_t_exposer_t;
        vdouble1d_t_exposer_t vdouble1d_t_exposer = vdouble1d_t_exposer_t( "vdouble1d_t" );
        bp::scope vdouble1d_t_scope( vdouble1d_t_exposer );
        vdouble1d_t_exposer.def( bp::vector_indexing_suite< ::std::vector< double >, true >() );
    }

}
