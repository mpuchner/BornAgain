// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "Bin.h"
#include "Crystal.h"
#include "DiffuseParticleInfo.h"
#include "FTDistributions.h"
#include "FormFactorBox.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorParallelepiped.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "HomogeneousMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Instrument.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "InterferenceFunction2DLattice.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "InterferenceFunctionNone.h"
#include "Lattice.h"
#include "Lattice2DIFParameters.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "Lattice2DIFParameters.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "Particle.h"
#include "ParticleBuilder.h"
#include "ParticleCoreShell.h"
#include "ParticleDecoration.h"
#include "ParticleInfo.h"
#include "PositionParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Simulation.h"
#include "SimulationParameters.h"
#include "IStochasticParameter.h"
#include "StochasticGaussian.h"
#include "StochasticSampledParameter.h"
#include "StochasticDoubleGate.h"
#include "Transform3D.h"
#include "Types.h"
#include "Units.h"
#include "StochasticParameter_t.pypp.h"

namespace bp = boost::python;

struct StochasticParameter_less__double__greater__wrapper : StochasticParameter< double >, bp::wrapper< StochasticParameter< double > > {

    StochasticParameter_less__double__greater__wrapper(double average )
    : StochasticParameter<double>( average )
      , bp::wrapper< StochasticParameter< double > >(){
        // constructor
    
    }

    virtual ::StochasticParameter< double > * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual double getFWHM(  ) const  {
        if( bp::override func_getFWHM = this->get_override( "getFWHM" ) )
            return func_getFWHM(  );
        else{
            return this->StochasticParameter< double >::getFWHM(  );
        }
    }
    
    double default_getFWHM(  ) const  {
        return StochasticParameter< double >::getFWHM( );
    }

    virtual double getRandom(  ) {
        if( bp::override func_getRandom = this->get_override( "getRandom" ) )
            return func_getRandom(  );
        else{
            return this->StochasticParameter< double >::getRandom(  );
        }
    }
    
    double default_getRandom(  ) {
        return StochasticParameter< double >::getRandom( );
    }

    virtual double probabilityDensity( double value ) const {
        bp::override func_probabilityDensity = this->get_override( "probabilityDensity" );
        return func_probabilityDensity( value );
    }

    virtual void setToAverage(  ) {
        if( bp::override func_setToAverage = this->get_override( "setToAverage" ) )
            func_setToAverage(  );
        else{
            this->StochasticParameter< double >::setToAverage(  );
        }
    }
    
    void default_setToAverage(  ) {
        StochasticParameter< double >::setToAverage( );
    }

    virtual void setToRandom(  ){
        bp::override func_setToRandom = this->get_override( "setToRandom" );
        func_setToRandom(  );
    }

};

void register_StochasticParameter_t_class(){

    bp::class_< StochasticParameter_less__double__greater__wrapper, bp::bases< IStochasticParameter >, boost::noncopyable >( "StochasticParameter_t", bp::init< double >(( bp::arg("average") )) )    
        .def( 
            "clone"
            , bp::pure_virtual( (::StochasticParameter< double > * ( ::StochasticParameter<double>::* )(  ) const)(&::StochasticParameter< double >::clone) )
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "getAverage"
            , (double ( ::StochasticParameter<double>::* )(  ) )(& ::StochasticParameter< double >::getAverage ) )    
        .def( 
            "getCurrent"
            , (double ( ::StochasticParameter<double>::* )(  ) const)(& ::StochasticParameter< double >::getCurrent ) )    
        .def( 
            "getFWHM"
            , (double ( ::StochasticParameter<double>::* )(  ) const)(&::StochasticParameter< double >::getFWHM)
            , (double ( StochasticParameter_less__double__greater__wrapper::* )(  ) const)(&StochasticParameter_less__double__greater__wrapper::default_getFWHM) )    
        .def( 
            "getRandom"
            , (double ( ::StochasticParameter<double>::* )(  ) )(&::StochasticParameter< double >::getRandom)
            , (double ( StochasticParameter_less__double__greater__wrapper::* )(  ) )(&StochasticParameter_less__double__greater__wrapper::default_getRandom) )    
        .def( 
            "probabilityDensity"
            , bp::pure_virtual( (double ( ::StochasticParameter<double>::* )( double ) const)(&::StochasticParameter< double >::probabilityDensity) )
            , ( bp::arg("value") ) )    
        .def( 
            "setToAverage"
            , (void ( ::StochasticParameter<double>::* )(  ) )(&::StochasticParameter< double >::setToAverage)
            , (void ( StochasticParameter_less__double__greater__wrapper::* )(  ) )(&StochasticParameter_less__double__greater__wrapper::default_setToAverage) )    
        .def( 
            "setToRandom"
            , bp::pure_virtual( (void ( ::IStochasticParameter::* )(  ) )(&::IStochasticParameter::setToRandom) ) );

}
