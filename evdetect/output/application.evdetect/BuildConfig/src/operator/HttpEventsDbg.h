// eJyVkE9Pg0AQxbNXPoVpPNCDLOClWU_0U1NgK2ASNx4bABtbC7jo7QKjxuwv9E_0NJnTnMYea938sYXTstilrgwFjYGlQN8Yg7tk9mjkNx0Jwu_0aaHOO39JC7fD2YRRUI_0HlbmIQihCl7BqWY_1jgdI1uo2CWB7WHWbaOcVSRTrp_0h57RZxF6eLYZkH4Z6X4E_1SiUZopRpODQLPGpMVjZC0V7A3Oss55V3BkedIiwwzIpXkk2bKKbQCvHZJuo0Y_0y0nEQSOtA_1raizGjqr7VuYolDSMvVw_0oUFIrKV9tndKjrs3o2SK46K05_1M769P6u80l3T8eY_0vJ78Y7ozzyjSdgTtP9AuJ6I6U


#ifndef SPL_OPER_INSTANCE_HTTPEVENTSDBG_H_
#define SPL_OPER_INSTANCE_HTTPEVENTSDBG_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
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

#include "../type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.h"
#include "../type/BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2.h"


#define MY_OPERATOR HttpEventsDbg$OP
#define MY_BASE_OPERATOR HttpEventsDbg_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr IPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Tuple const & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    
    
protected:
    Mutex $svMutex;
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
   
   
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_HTTPEVENTSDBG_H_

