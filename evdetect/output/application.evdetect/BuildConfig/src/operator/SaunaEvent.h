// eJzVlG1P4kAQx7Nv_1RQbczGQGNgW5UHvLkEoohQqgoC_0aQod261tt7RboBq_1_020L9FDvA5zbN53_1TKaz85tpFLilmFOX8uTiohVHnHlIQkQ8Mjoulco8CaB8BbdrM5komvXS7Nua8jowVBqRR_1suZp3_0LXHb02pNHpHhPNElNUnGujSonAX3_1Ydup6GF_1RmrysuFpdbi_0u3ohjiB04qn1VWDtHxH0yVZjR2v13rVSSuRnPFovlRq07DXXTxOu6P642LT9Awa6ERhzbvGpG4RrbORNvXaa32wdHpJyT7_0XOpClOo0h7bW8ZdMpVOjP3TscDV4qtArTkc1V6VygyceiErvrUZVmQ6UcKJaRqXNxldEJ1Zgy2Aq_1Vnie5sncSnTf62c28PN_0Rjs2dRMgrYuPWvXG_1VmML8fXMUbQ1bM_0qzdVprK03gyW8fDVnxebT451gMsdeKANu1KVJeoTNbL_02vLi56TRGuvvLR8gs6QQPCDoNGdenHx7DKDV2SUadI_1NHmrhREPqW9ttcpWi6mfhaGyzTwoiwgwvMgwPeqX1yx8iQJjAWVYmcBhwcumwQ3kMx9S5Cl4GrAwL_0T_1Bo88FGaj_0naExaHPuFAo7OovWcB1Dl5w43cKRfwbZ60s4pMT_1CEkBNfgdAXd2KOmWII8lhSLRZzlTc9b_1pYek_0E3fNCg7zRuOG0K_1vVdy9_1DO80gycVLHMVzj3JcSO_01VStCfcdrm7pQIMXLHN370fsRQg0UcYGc_0S1mAtqvEJtHEK4yfUw9QGKLqmcozYn2m7ebptz_0PDq5w4R1wESCXFhT3_0yCYYoPtcEKAaI0v1TNHKMAwOz5jB_0K1_0JPfKilm8m_0buZ3Ipdtq_0gFGNyGcGK4sWgDjwMXfu4g4AMwpxkA_1AnL6a6j2RB_1MASY3P4MJnfswZxmTcVfsRw4_1mI5EHMsvwUPWIFgvB8gIhD9AdLSGVV


#ifndef SPL_OPER_INSTANCE_SAUNAEVENT_H_
#define SPL_OPER_INSTANCE_SAUNAEVENT_H_

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

#include "../type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h"
#include "../type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.h"

#include <bitset>

#define MY_OPERATOR SaunaEvent$OP
#define MY_BASE_OPERATOR SaunaEvent_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy IPort0Type;
    typedef SPL::BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple & tuple, uint32_t port);
    void processRaw(Tuple & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::float32 lit$0;
    SPL::float32 lit$1;
    SPL::rstring lit$2;
    SPL::uint32 lit$3;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
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
#endif // SPL_OPER_INSTANCE_SAUNAEVENT_H_

