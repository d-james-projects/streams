// eJzFUtFOwjAUTf_0ELD6AJi0jPpi_0IUqIDiRhxuduu2GFrZ23F_0f4eisgCROjb6ZPvb3nnnN6T2pLrpOSO0JQpXvn2gDxnKiSchLH87l1xELW9ydkAeeCmgrELTzUOF3Ug9l0_0bp1N1GkzeP23k2GI8yHL8jzwAMGrNB00WeLeSQlegZtlmxXC1s1JnJbgjiIUFmpjagtrl2lUhDwlgFBSiJTpJixBvrsmqWFcm6mSmCtaaeE3SD90SL_1cvhUAQY9NiQPSTYEYwTYE0Q6QYWN99Li6O7u441JSVvjpHwm7a01Ui6BYmuLtaY7jV62xab7B0VBr9e56pw2Cl1WhSh0Is6bWCkvu637X4Tayq_1H1qawKoNMXH6XlYN_1wZE1BIZin6L23sJDXE5hGyzON4atxs_0Q6sriMXG_1hZRphrtgM49dOWsW_0_1HHr_1sA1gUJBf


#include "./HttpEvents.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR HttpEvents_Base
#define MY_OPERATOR HttpEvents$OP






#include <dlfcn.h>

#include <SPL/Toolkit/JavaOp.h>
#include <SPL/Toolkit/RuntimeException.h>

MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
{
  
  /* Get a handle to the Java virtual machine */
  SPL::JNI::JVMControl *jvmControl = SPL::JNI::JVMControl::getJVM();
   
  /* Attach to the JVM  for the duration of the initialization */
  JNIEnv * env = jvmControl->attach();

  /* How we invoke methods against an OperatorSetup instance */
  SPL::JNI::OpSetupInvoker* osi = jvmControl->getOpSetupInvoker();

  /* OperatorSetup instance specific to this operator */
  jobject setup = osi->newSetup(env, this); 

  /**
     Pass the parameters into my OperatorSetup instance.
  */
     osi->setParameter(env, setup, "className", SPL::rstring("com.ibm.streamsx.inet.http.HTTPPostOper"));
   osi->setParameter(env, setup, "classLibrary", (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.inet")) + SPL::rstring("/impl/lib/com.ibm.streamsx.inet.jar")));
   osi->setParameter(env, setup, "classLibrary", (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.inet")) + SPL::rstring("/opt/downloaded/*")));
   osi->setParameter(env, setup, "headerContentType", lit$0);
   osi->setParameter(env, setup, "url", lit$1);


  /**
    Pass input port information into the Java operator.
 
    Are logic clauses present.
   
    Pass the windowing information for each port as
    a list of values for the parameter '[window].N' where
    N is the index of the windowed input port.
  */
     osi->setParameter(env, setup, "[inputPortLogic].0", "none");
 hasTupleLogic = false;


  
  /* At this point all the initialization information has been
     passed to OperatorSetup. Create a JNIBridge instance object
     we use to communicate with the user's Operator implementation
     at runtime.
  */
  
  _bi = jvmControl->getBridgeInvoker();
  _bridge = _bi->newBridge(env, this, setup);
        
  /* Completed Java initialization, detach from the JVM */
  jvmControl->detach();

  setupStateHandler();

  void * handle = dlopen("libstreams-stdtk-javaop.so", RTLD_LAZY);
  if (!handle) {
    const FormattableMessage& m = SPL_APPLICATION_RUNTIME_EXCEPTION("libstreams-stdtk-javaop.so");
    THROW_STRING(SPLRuntimeJavaOperator, m);
  }
  _fp = (FP) dlsym(handle, "callProcessTupleWithNativeByteBuffer");
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR() 
{
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::setupStateHandler()
{
    _stateHandler.reset(new SPL::JNI::JavaOpStateHandler(_bi, _bridge));
    getContext().registerStateHandler(*_stateHandler);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady() 
{
    _bi->allPortsReady(_bridge);
    createThreads(1);
}
 
void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown() 
{
   _bi->shutdown(_bridge);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t idx)
{
   _bi->complete(_bridge);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple & tuple, uint32_t port)
{
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
   _bi->processTuple(_bridge, tuple, port);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{
   _bi->processPunctuation(_bridge, punct, port);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("HttpEvents",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator()  {
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    initRTC(*this, lit$1, "lit$1");
    param$className$0 = SPL::rstring("com.ibm.streamsx.inet.http.HTTPPostOper");
    addParameterValue ("className", SPL::ConstValueHandle(param$className$0));
    param$classLibrary$0 = (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.inet")) + SPL::rstring("/impl/lib/com.ibm.streamsx.inet.jar"));
    addParameterValue ("classLibrary", SPL::ConstValueHandle(param$classLibrary$0));
    param$classLibrary$1 = (SPL::Functions::Utility::getToolkitDirectory(SPL::rstring("com.ibm.streamsx.inet")) + SPL::rstring("/opt/downloaded/*"));
    addParameterValue ("classLibrary", SPL::ConstValueHandle(param$classLibrary$1));
    addParameterValue ("headerContentType", SPL::ConstValueHandle(lit$0));
    addParameterValue ("url", SPL::ConstValueHandle(lit$1));
    (void) getParameters(); // ensure thread safety by initializing here
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}

void MY_BASE_OPERATOR::tupleLogic(Tuple const & tuple, uint32_t port) {
}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::punctPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    {
        punctNoPermitProcessRaw(punct, port);
    }
}

void MY_BASE_OPERATOR::punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    switch(punct) {
    case Punctuation::WindowMarker:
        punctLogic(punct, port);
        process(punct, port);
        break;
    case Punctuation::FinalMarker:
        punctLogic(punct, port);
        process(punct, port);
        break;
    case Punctuation::DrainMarker:
    case Punctuation::ResetMarker:
    case Punctuation::ResumeMarker:
        break;
    case Punctuation::SwitchMarker:
        javaopInternalAction(punct, port);
        break;
    case Punctuation::WatermarkMarker:
        break;
    default:
        break;
    }
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    switch(port) {
    case 0:
        punctNoPermitProcessRaw(punct, port);
        break;
    }
}



void MY_BASE_OPERATOR::checkpointStateVariables(NetworkByteBuffer & opstate) const {
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return false;
}

void MY_BASE_OPERATOR::resetToInitialStateRaw() {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->resetToInitialState();
    }
    resetStateVariablesToInitialState();
}

void MY_BASE_OPERATOR::checkpointRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->checkpoint(ckpt);
    }
    checkpointStateVariables(ckpt);
}

void MY_BASE_OPERATOR::resetRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->reset(ckpt);
    }
    resetStateVariables(ckpt);
}




