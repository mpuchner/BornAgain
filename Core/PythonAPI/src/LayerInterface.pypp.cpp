// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence 
//! @brief automatically generated boost::python code for PythonCoreAPI  

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "LayerInterface.pypp.h"

namespace bp = boost::python;

struct LayerInterface_wrapper : LayerInterface, bp::wrapper< LayerInterface > {

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else{
            return this->IParameterized::areParametersChanged(  );
        }
    }
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else{
            this->IParameterized::clearParameterPool(  );
        }
    }
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
    }

    virtual ::ICompositeSample * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->ICompositeSample::clone(  );
        }
    }
    
    ::ICompositeSample * default_clone(  ) const  {
        return ICompositeSample::clone( );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else{
            return this->IParameterized::createParameterTree(  );
        }
    }
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual ::ICompositeSample * getCompositeSample(  ) {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample * default_getCompositeSample(  ) {
        return ICompositeSample::getCompositeSample( );
    }

    virtual ::ICompositeSample const * getCompositeSample(  ) const  {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample const * default_getCompositeSample(  ) const  {
        return ICompositeSample::getCompositeSample( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else{
            this->IParameterized::printParameters(  );
        }
    }
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual void registerParameter( ::std::string const & name, double * parpointer ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer );
        }
        else{
            IParameterized::registerParameter( name, parpointer );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer ){
        if( dynamic_cast< LayerInterface_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else{
            return this->IParameterized::setParameterValue( name, value );
        }
    }
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else{
            this->IParameterized::setParametersAreChanged(  );
        }
    }
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

    virtual ::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ICompositeSample::size(  );
        }
    }
    
    ::size_t default_size(  ) const  {
        return ICompositeSample::size( );
    }

};

void register_LayerInterface_class(){

    { //::LayerInterface
        typedef bp::class_< LayerInterface_wrapper, bp::bases< ICompositeSample >, boost::noncopyable > LayerInterface_exposer_t;
        LayerInterface_exposer_t LayerInterface_exposer = LayerInterface_exposer_t( "LayerInterface", bp::no_init );
        bp::scope LayerInterface_scope( LayerInterface_exposer );
        { //::LayerInterface::getLayerBottom
        
            typedef ::Layer const * ( ::LayerInterface::*getLayerBottom_function_type )(  ) const;
            
            LayerInterface_exposer.def( 
                "getLayerBottom"
                , getLayerBottom_function_type( &::LayerInterface::getLayerBottom )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::LayerInterface::getLayerTop
        
            typedef ::Layer const * ( ::LayerInterface::*getLayerTop_function_type )(  ) const;
            
            LayerInterface_exposer.def( 
                "getLayerTop"
                , getLayerTop_function_type( &::LayerInterface::getLayerTop )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::LayerInterface::getRoughness
        
            typedef ::LayerRoughness const * ( ::LayerInterface::*getRoughness_function_type )(  ) const;
            
            LayerInterface_exposer.def( 
                "getRoughness"
                , getRoughness_function_type( &::LayerInterface::getRoughness )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::LayerInterface::setRoughness
        
            typedef void ( ::LayerInterface::*setRoughness_function_type )( ::LayerRoughness const & ) ;
            
            LayerInterface_exposer.def( 
                "setRoughness"
                , setRoughness_function_type( &::LayerInterface::setRoughness )
                , ( bp::arg("roughness") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( LayerInterface_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            LayerInterface_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&LayerInterface_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type )(  ) ;
            typedef void ( LayerInterface_wrapper::*default_clearParameterPool_function_type )(  ) ;
            
            LayerInterface_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&LayerInterface_wrapper::default_clearParameterPool) );
        
        }
        { //::ICompositeSample::clone
        
            typedef ::ICompositeSample * ( ::ICompositeSample::*clone_function_type )(  ) const;
            typedef ::ICompositeSample * ( LayerInterface_wrapper::*default_clone_function_type )(  ) const;
            
            LayerInterface_exposer.def( 
                "clone"
                , clone_function_type(&::ICompositeSample::clone)
                , default_clone_function_type(&LayerInterface_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( LayerInterface_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            LayerInterface_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&LayerInterface_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample * ( ::ICompositeSample::*getCompositeSample_function_type )(  ) ;
            typedef ::ICompositeSample * ( LayerInterface_wrapper::*default_getCompositeSample_function_type )(  ) ;
            
            LayerInterface_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&LayerInterface_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ICompositeSample::*getCompositeSample_function_type )(  ) const;
            typedef ::ICompositeSample const * ( LayerInterface_wrapper::*default_getCompositeSample_function_type )(  ) const;
            
            LayerInterface_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&LayerInterface_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( LayerInterface_wrapper::*default_printParameters_function_type )(  ) const;
            
            LayerInterface_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&LayerInterface_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            LayerInterface_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &LayerInterface_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type )( ::std::string const &,double ) ;
            typedef bool ( LayerInterface_wrapper::*default_setParameterValue_function_type )( ::std::string const &,double ) ;
            
            LayerInterface_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&LayerInterface_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( LayerInterface_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            LayerInterface_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&LayerInterface_wrapper::default_setParametersAreChanged) );
        
        }
        { //::ICompositeSample::size
        
            typedef ::size_t ( ::ICompositeSample::*size_function_type )(  ) const;
            typedef ::size_t ( LayerInterface_wrapper::*default_size_function_type )(  ) const;
            
            LayerInterface_exposer.def( 
                "size"
                , size_function_type(&::ICompositeSample::size)
                , default_size_function_type(&LayerInterface_wrapper::default_size) );
        
        }
    }

}
