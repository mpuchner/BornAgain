// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "IDetector2D.pypp.h"

namespace bp = boost::python;

struct IDetector2D_wrapper : IDetector2D, bp::wrapper< IDetector2D > {

    IDetector2D_wrapper( )
    : IDetector2D( )
      , bp::wrapper< IDetector2D >(){
        // null constructor
    m_pyobj = 0;
    }

    IDetector2D_wrapper(::IDetector2D const & other )
    : IDetector2D( boost::ref(other) )
      , bp::wrapper< IDetector2D >(){
        // copy constructor
    m_pyobj = 0;
    }

    virtual ::IDetector2D * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual ::IAxis * createAxis( ::std::size_t index, ::std::size_t n_bins, double min, double max ) const {
        bp::override func_createAxis = this->get_override( "createAxis" );
        return func_createAxis( index, n_bins, min, max );
    }

    virtual ::IPixelMap * createPixelMap( ::std::size_t index ) const {
        bp::override func_createPixelMap = this->get_override( "createPixelMap" );
        return func_createPixelMap( index );
    }

    virtual ::std::string getAxisName( ::std::size_t index ) const {
        bp::override func_getAxisName = this->get_override( "getAxisName" );
        return func_getAxisName( index );
    }

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

    virtual void registerParameter( ::std::string const & name, double * parpointer, ::AttLimits const & limits=AttLimits::limitless( ) ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer, limits );
        }
        else{
            IParameterized::registerParameter( name, parpointer, boost::ref(limits) );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer, ::AttLimits const & limits=AttLimits::limitless( ) ){
        if( dynamic_cast< IDetector2D_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ), limits);
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ), limits);
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

    PyObject* m_pyobj;

};

void register_IDetector2D_class(){

    { //::IDetector2D
        typedef bp::class_< IDetector2D_wrapper, bp::bases< IParameterized >, std::auto_ptr< IDetector2D_wrapper >, boost::noncopyable > IDetector2D_exposer_t;
        IDetector2D_exposer_t IDetector2D_exposer = IDetector2D_exposer_t( "IDetector2D", "The detector interface.", bp::no_init );
        bp::scope IDetector2D_scope( IDetector2D_exposer );
        IDetector2D_exposer.def( bp::init< >() );
        IDetector2D_exposer.def( bp::init< IDetector2D const & >(( bp::arg("other") )) );
        { //::IDetector2D::addMask
        
            typedef void ( ::IDetector2D::*addMask_function_type)( ::Geometry::IShape2D const &,bool ) ;
            
            IDetector2D_exposer.def( 
                "addMask"
                , addMask_function_type( &::IDetector2D::addMask )
                , ( bp::arg("shape"), bp::arg("mask_value")=(bool)(true) )
                , "Adds mask of given shape to the stack of detector masks. The mask value 'true' means that the channel will be excluded from the simulation. The mask which is added last has priority. @param shape The shape of mask (Rectangle, Polygon, Line, Ellipse) @mask_value The value of mask \n\n:Parameters:\n  - 'shape' - The shape of mask (Rectangle, Polygon, Line, Ellipse)\n" );
        
        }
        { //::IDetector2D::clear
        
            typedef void ( ::IDetector2D::*clear_function_type)(  ) ;
            
            IDetector2D_exposer.def( 
                "clear"
                , clear_function_type( &::IDetector2D::clear ) );
        
        }
        { //::IDetector2D::clone
        
            typedef ::IDetector2D * ( ::IDetector2D::*clone_function_type)(  ) const;
            
            IDetector2D_exposer.def( 
                "clone"
                , bp::pure_virtual( clone_function_type(&::IDetector2D::clone) )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IDetector2D::createAxis
        
            typedef ::IAxis * ( IDetector2D_wrapper::*createAxis_function_type)( ::std::size_t,::std::size_t,double,double ) const;
            
            IDetector2D_exposer.def( 
                "createAxis"
                , createAxis_function_type( &IDetector2D_wrapper::createAxis )
                , ( bp::arg("index"), bp::arg("n_bins"), bp::arg("min"), bp::arg("max") )
                , bp::return_value_policy< bp::manage_new_object >()
                , "Generates an axis with correct name and default binning for given index." );
        
        }
        { //::IDetector2D::createPixelMap
        
            typedef ::IPixelMap * ( IDetector2D_wrapper::*createPixelMap_function_type)( ::std::size_t ) const;
            
            IDetector2D_exposer.def( 
                "createPixelMap"
                , createPixelMap_function_type( &IDetector2D_wrapper::createPixelMap )
                , ( bp::arg("index") )
                , bp::return_value_policy< bp::manage_new_object >()
                , "Create an IPixelMap for the given OutputData object and index." );
        
        }
        { //::IDetector2D::getAxis
        
            typedef ::IAxis const & ( ::IDetector2D::*getAxis_function_type)( ::std::size_t ) const;
            
            IDetector2D_exposer.def( 
                "getAxis"
                , getAxis_function_type( &::IDetector2D::getAxis )
                , ( bp::arg("index") )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::IDetector2D::getAxisName
        
            typedef ::std::string ( IDetector2D_wrapper::*getAxisName_function_type)( ::std::size_t ) const;
            
            IDetector2D_exposer.def( 
                "getAxisName"
                , getAxisName_function_type( &IDetector2D_wrapper::getAxisName )
                , ( bp::arg("index") )
                , "Returns the name for the axis with given index." );
        
        }
        { //::IDetector2D::getDetectorMask
        
            typedef ::DetectorMask const * ( ::IDetector2D::*getDetectorMask_function_type)(  ) const;
            
            IDetector2D_exposer.def( 
                "getDetectorMask"
                , getDetectorMask_function_type( &::IDetector2D::getDetectorMask )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Put the mask for all detector channels (i.e. exclude whole detector from the analysis)." );
        
        }
        { //::IDetector2D::getDetectorResolutionFunction
        
            typedef ::IDetectorResolution const * ( ::IDetector2D::*getDetectorResolutionFunction_function_type)(  ) const;
            
            IDetector2D_exposer.def( 
                "getDetectorResolutionFunction"
                , getDetectorResolutionFunction_function_type( &::IDetector2D::getDetectorResolutionFunction )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Applies the detector resolution to the given intensity maps." );
        
        }
        { //::IDetector2D::getDimension
        
            typedef ::std::size_t ( ::IDetector2D::*getDimension_function_type)(  ) const;
            
            IDetector2D_exposer.def( 
                "getDimension"
                , getDimension_function_type( &::IDetector2D::getDimension ) );
        
        }
        { //::IDetector2D::hasMasks
        
            typedef bool ( ::IDetector2D::*hasMasks_function_type)(  ) const;
            
            IDetector2D_exposer.def( 
                "hasMasks"
                , hasMasks_function_type( &::IDetector2D::hasMasks )
                , "return true if has masks." );
        
        }
        { //::IDetector2D::isMasked
        
            typedef bool ( ::IDetector2D::*isMasked_function_type)( ::std::size_t ) const;
            
            IDetector2D_exposer.def( 
                "isMasked"
                , isMasked_function_type( &::IDetector2D::isMasked )
                , ( bp::arg("index") ) );
        
        }
        { //::IDetector2D::maskAll
        
            typedef void ( ::IDetector2D::*maskAll_function_type)(  ) ;
            
            IDetector2D_exposer.def( 
                "maskAll"
                , maskAll_function_type( &::IDetector2D::maskAll )
                , "Put the mask for all detector channels (i.e. exclude whole detector from the analysis)." );
        
        }
        { //::IDetector2D::matchDetectorAxes
        
            typedef void ( ::IDetector2D::*matchDetectorAxes_function_type)( ::OutputData< double > const & ) ;
            
            IDetector2D_exposer.def( 
                "matchDetectorAxes"
                , matchDetectorAxes_function_type( &::IDetector2D::matchDetectorAxes )
                , ( bp::arg("output_data") )
                , "Sets detector parameters using axes of output data." );
        
        }
        { //::IDetector2D::removeMasks
        
            typedef void ( ::IDetector2D::*removeMasks_function_type)(  ) ;
            
            IDetector2D_exposer.def( 
                "removeMasks"
                , removeMasks_function_type( &::IDetector2D::removeMasks )
                , "removes all masks from the detector." );
        
        }
        { //::IDetector2D::setAnalyzerProperties
        
            typedef void ( ::IDetector2D::*setAnalyzerProperties_function_type)( ::kvector_t const &,double,double ) ;
            
            IDetector2D_exposer.def( 
                "setAnalyzerProperties"
                , setAnalyzerProperties_function_type( &::IDetector2D::setAnalyzerProperties )
                , ( bp::arg("direction"), bp::arg("efficiency"), bp::arg("total_transmission")=1.0e+0 )
                , "Sets the polarization analyzer characteristics of the detector." );
        
        }
        { //::IDetector2D::setDetectorAxes
        
            typedef void ( ::IDetector2D::*setDetectorAxes_function_type)( ::IAxis const &,::IAxis const & ) ;
            
            IDetector2D_exposer.def( 
                "setDetectorAxes"
                , setDetectorAxes_function_type( &::IDetector2D::setDetectorAxes )
                , ( bp::arg("axis0"), bp::arg("axis1") )
                , "Sets detector parameters using axes." );
        
        }
        { //::IDetector2D::setDetectorParameters
        
            typedef void ( ::IDetector2D::*setDetectorParameters_function_type)( ::std::size_t,double,double,::std::size_t,double,double ) ;
            
            IDetector2D_exposer.def( 
                "setDetectorParameters"
                , setDetectorParameters_function_type( &::IDetector2D::setDetectorParameters )
                , ( bp::arg("n_x"), bp::arg("x_min"), bp::arg("x_max"), bp::arg("n_y"), bp::arg("y_min"), bp::arg("y_max") )
                , "Sets detector parameters using angle ranges." );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type)(  ) ;
            typedef bool ( IDetector2D_wrapper::*default_areParametersChanged_function_type)(  ) ;
            
            IDetector2D_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&IDetector2D_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type)(  ) ;
            typedef void ( IDetector2D_wrapper::*default_clearParameterPool_function_type)(  ) ;
            
            IDetector2D_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&IDetector2D_wrapper::default_clearParameterPool) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type)(  ) const;
            typedef ::ParameterPool * ( IDetector2D_wrapper::*default_createParameterTree_function_type)(  ) const;
            
            IDetector2D_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&IDetector2D_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type)(  ) const;
            typedef void ( IDetector2D_wrapper::*default_printParameters_function_type)(  ) const;
            
            IDetector2D_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&IDetector2D_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int,::AttLimits const & );
            
            IDetector2D_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &IDetector2D_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer"), bp::arg("limits")=AttLimits::limitless( ) )
                , "main method to register data address in the pool." );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type)( ::std::string const &,double ) ;
            typedef bool ( IDetector2D_wrapper::*default_setParameterValue_function_type)( ::std::string const &,double ) ;
            
            IDetector2D_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&IDetector2D_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type)(  ) ;
            typedef void ( IDetector2D_wrapper::*default_setParametersAreChanged_function_type)(  ) ;
            
            IDetector2D_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&IDetector2D_wrapper::default_setParametersAreChanged) );
        
        }
    }

}