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
#include "IndexVector3D.pypp.h"

namespace bp = boost::python;

void register_IndexVector3D_class(){

    { //::Geometry::BasicVector3D< int >
        typedef bp::class_< Geometry::BasicVector3D< int > > IndexVector3D_exposer_t;
        IndexVector3D_exposer_t IndexVector3D_exposer = IndexVector3D_exposer_t( "IndexVector3D", bp::init< >() );
        bp::scope IndexVector3D_scope( IndexVector3D_exposer );
        IndexVector3D_exposer.def( bp::init< int const &, int const &, int const & >(( bp::arg("x1"), bp::arg("y1"), bp::arg("z1") )) );
        IndexVector3D_exposer.def( bp::self *= bp::other< double >() );
        IndexVector3D_exposer.def( bp::self += bp::self );
        IndexVector3D_exposer.def( bp::self -= bp::self );
        IndexVector3D_exposer.def( bp::self /= bp::other< double >() );
        { //::Geometry::BasicVector3D< int >::operator=
        
            typedef Geometry::BasicVector3D< int > exported_class_t;
            typedef ::Geometry::BasicVector3D< int > & ( exported_class_t::*assign_function_type )( ::Geometry::BasicVector3D< int > const & ) ;
            
            IndexVector3D_exposer.def( 
                "assign"
                , assign_function_type( &::Geometry::BasicVector3D< int >::operator= )
                , ( bp::arg("v") )
                , bp::return_self< >() );
        
        }
        { //::Geometry::BasicVector3D< int >::operator[]
        
            typedef Geometry::BasicVector3D< int > exported_class_t;
            typedef int ( exported_class_t::*__getitem___function_type )( int ) const;
            
            IndexVector3D_exposer.def( 
                "__getitem__"
                , __getitem___function_type( &::Geometry::BasicVector3D< int >::operator[] )
                , ( bp::arg("i") ) );
        
        }
        { //::Geometry::BasicVector3D< int >::operator[]
        
            typedef Geometry::BasicVector3D< int > exported_class_t;
            typedef int & ( exported_class_t::*__getitem___function_type )( int ) ;
            
            IndexVector3D_exposer.def( 
                "__getitem__"
                , __getitem___function_type( &::Geometry::BasicVector3D< int >::operator[] )
                , ( bp::arg("i") )
                , bp::return_value_policy< bp::copy_non_const_reference >() );
        
        }
        { //::Geometry::BasicVector3D< int >::setLambdaAlphaPhi
        
            typedef Geometry::BasicVector3D< int > exported_class_t;
            typedef void ( exported_class_t::*setLambdaAlphaPhi_function_type )( int const &,int const &,int const & ) ;
            
            IndexVector3D_exposer.def( 
                "setLambdaAlphaPhi"
                , setLambdaAlphaPhi_function_type( &::Geometry::BasicVector3D< int >::setLambdaAlphaPhi )
                , ( bp::arg("_lambda"), bp::arg("_alpha"), bp::arg("_phi") ) );
        
        }
        { //::Geometry::BasicVector3D< int >::setX
        
            typedef Geometry::BasicVector3D< int > exported_class_t;
            typedef void ( exported_class_t::*setX_function_type )( int const & ) ;
            
            IndexVector3D_exposer.def( 
                "setX"
                , setX_function_type( &::Geometry::BasicVector3D< int >::setX )
                , ( bp::arg("a") ) );
        
        }
        { //::Geometry::BasicVector3D< int >::setXYZ
        
            typedef Geometry::BasicVector3D< int > exported_class_t;
            typedef void ( exported_class_t::*setXYZ_function_type )( int const &,int const &,int const & ) ;
            
            IndexVector3D_exposer.def( 
                "setXYZ"
                , setXYZ_function_type( &::Geometry::BasicVector3D< int >::setXYZ )
                , ( bp::arg("x1"), bp::arg("y1"), bp::arg("z1") ) );
        
        }
        { //::Geometry::BasicVector3D< int >::setY
        
            typedef Geometry::BasicVector3D< int > exported_class_t;
            typedef void ( exported_class_t::*setY_function_type )( int const & ) ;
            
            IndexVector3D_exposer.def( 
                "setY"
                , setY_function_type( &::Geometry::BasicVector3D< int >::setY )
                , ( bp::arg("a") ) );
        
        }
        { //::Geometry::BasicVector3D< int >::setZ
        
            typedef Geometry::BasicVector3D< int > exported_class_t;
            typedef void ( exported_class_t::*setZ_function_type )( int const & ) ;
            
            IndexVector3D_exposer.def( 
                "setZ"
                , setZ_function_type( &::Geometry::BasicVector3D< int >::setZ )
                , ( bp::arg("a") ) );
        
        }
        { //::Geometry::BasicVector3D< int >::x
        
            typedef Geometry::BasicVector3D< int > exported_class_t;
            typedef int ( exported_class_t::*x_function_type )(  ) const;
            
            IndexVector3D_exposer.def( 
                "x"
                , x_function_type( &::Geometry::BasicVector3D< int >::x ) );
        
        }
        { //::Geometry::BasicVector3D< int >::y
        
            typedef Geometry::BasicVector3D< int > exported_class_t;
            typedef int ( exported_class_t::*y_function_type )(  ) const;
            
            IndexVector3D_exposer.def( 
                "y"
                , y_function_type( &::Geometry::BasicVector3D< int >::y ) );
        
        }
        { //::Geometry::BasicVector3D< int >::z
        
            typedef Geometry::BasicVector3D< int > exported_class_t;
            typedef int ( exported_class_t::*z_function_type )(  ) const;
            
            IndexVector3D_exposer.def( 
                "z"
                , z_function_type( &::Geometry::BasicVector3D< int >::z ) );
        
        }
    }

}
