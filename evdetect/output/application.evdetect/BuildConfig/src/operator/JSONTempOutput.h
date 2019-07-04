// eJzFks1u4jAUheU3qaIuQCPFkFGlUXYptJpCYFDtqio7J9wJLrEd7AsBnr5O6S_0lUheVKq_0udHz83eOTGxXKTIUOLQjlNuG9MzqO_0aoqgZsB_0zcmXdLxJyJBGFLcVkDPYVDbEYsi3uumO_0YGS7a54nwy4aK_0YnkHh_127TpENe2wzSEfrya7oD6fAk2kvccukTs6m14tOOA8_0ONbReFQsd_05Pmko93F24v0nPzpNb24gbCELnRgF9ghUzJTWtjV24SuRAYT0DhBzpTKAg2mhosPNSODcWCvwibJLGsfXXpS683duxFeTHogjfJBG0SYJenK0QLi3A3jqVmRV26186cG89zpcrnaM02sXxDcpS4jaOC0BuTLmQ2JfWAxu7bX2BJWi3T36dvBdSqaqSljKjx_1HvhfXXDrh_1BPRzxtzoNVgE647jNgWUlbF4_0vRl31JAIondl4qcEViDRu6rSJ5jUWLDQVXkf2kE_1o6eZ4aiCelVJvV72X4_0lDUrmCMrfNp4ojxdlzT5sL3Fy395rwctuz5Y

#include <SPL/Toolkit/JavaOp.h>


#ifndef SPL_OPER_INSTANCE_JSONTEMPOUTPUT_H_
#define SPL_OPER_INSTANCE_JSONTEMPOUTPUT_H_

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

#include "../type/BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0.h"
#include "../type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.h"

#include <bitset>

#define MY_OPERATOR JSONTempOutput$OP
#define MY_BASE_OPERATOR JSONTempOutput_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0 IPort0Type;
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
#endif // SPL_OPER_INSTANCE_JSONTEMPOUTPUT_H_

