// eJzFkk1vwjAMhpV_1gqodQJMaYNM09VZgaCvlQ2qnid1CsSDQJMUJn79_0KbANWJGmXaacbNmvHztvooTLR8LVBoEJvXFnWknPi5dZCrEKon6P1EjVvjpxXJeabQa0AcEau9FDPW7Wwl2kg0W0eQnjYdXHfivaBGF3NdgNW533JZv74dv9oDFwp86P_1nW9150sdvoxDLns7J70s9_1Eqf_0GeXE_0ktCpEkCPaGwsuKRrhXOdsQQorMZgIDF0zAwjUknIIZOUad1jAix2NAg9D207lxMrdxqWnaRocfdkb6dCfGOLR0sDbQQ4SId8hAy3dtKFenkft5cyMVxJ7XmvhqfcbD1vAiZWKp1z0_0JogRVuy79gcSqV0m3pvJBykaU05SNajD9jaNsuuP8F9DpjouQK0ADqYtzcbjxTaG6OX_1YHuxFO8GAhckdgBdLE1njk8wj7TGRYfoDzZMzFd1lOogpIrhqXCDu2RvI1o4PE19mt1gcDxCSz

#include <SPL/Toolkit/JavaOp.h>


#ifndef SPL_OPER_INSTANCE_JSONOUTPUT_H_
#define SPL_OPER_INSTANCE_JSONOUTPUT_H_

#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMS62TC1LzSsJqSxILTY0ArODSxJLMvPzYDKZuakALW4PBP.h"
#include "../type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.h"

#include <bitset>

#define MY_OPERATOR JSONOutput$OP
#define MY_BASE_OPERATOR JSONOutput_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS62TC1LzSsJqSxILTY0ArODSxJLMvPzYDKZuakALW4PBP IPort0Type;
    typedef SPL::BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    virtual void javaopInternalAction(Punctuation const & punct, uint32_t port) = 0;
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
    SPL::rstring param$className$0;
    SPL::rstring param$classLibrary$0;
    SPL::rstring param$classLibrary$1;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const;
    void restoreStateVariables(NetworkByteBuffer & opstate);
    void checkpointStateVariables(Checkpoint & ckpt);
    void resetStateVariables(Checkpoint & ckpt);
    void resetStateVariablesToInitialState();
    bool hasStateVariables() const;
    void resetToInitialStateRaw();
    void checkpointRaw(Checkpoint & ckpt);
    void resetRaw(Checkpoint & ckpt);

private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR
{
public:
  // constructor
  MY_OPERATOR();

  // destructor
  virtual ~MY_OPERATOR(); 

  // notify port readiness
  void allPortsReady(); 

  // notify termination
  void prepareToShutdown(); 

  // processing for source and threaded operators   
  void process(uint32_t idx);
    
  // tuple processing for mutating ports 
  void process(Tuple & tuple, uint32_t port);
    
  // tuple processing for non-mutating ports
  void process(Tuple const & tuple, uint32_t port);

  // punctuation processing
  void process(Punctuation const & punct, uint32_t port);

private:
  void setupStateHandler();

  // members
  
  /** How we invoke actions on the Java Operator implementation */
  SPL::JNI::JNIBridgeInvoker* _bi;
  
  /* The instance of the JNIBridge used to wrap the Java Operator implementation */
  jobject _bridge;

  typedef void (*FP)(SPL::JNI::JNIBridgeInvoker&, jobject, NativeByteBuffer &, uint32_t);
  FP _fp;
  
  bool hasTupleLogic;
  
  std::tr1::shared_ptr<SPL::StateHandler> _stateHandler;

public:
  virtual void javaopInternalAction(Punctuation const & punct, uint32_t port)
  {
     _bi->action(_bridge, punct, port);
  }
    
  // handle byte buffers being sent as is
  virtual void processRaw(NativeByteBuffer & buffer, uint32_t port)
  {
     (*_fp)(*_bi, _bridge, buffer, port);
  }
  
  //Java operators handle byte buffers directly
  virtual bool sendRawBufferData() { return !hasTupleLogic; }

  // Requests the blocking of a consistent region permit
  virtual void blockConsistentRegionPermit() {
      _bi->blockConsistentRegionPermit(_bridge);
  }

  // Gets the watermark for this operator
  virtual timestamp watermark() const {
      return _bi->watermark(_bridge);
  }
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_JSONOUTPUT_H_

