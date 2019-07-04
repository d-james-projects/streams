// eJzVlN1O6kAQx7O3PsXGnBhIDGyL8qEeE4QiaqEiCOhNU_0jYbm27pd0CxfjuZ1ukB_1U8wHF70_1nPZDo7v5lGgVuKOXUpT87OWnHEmYckRMQjo8NSqcyTAMpXcLsyk7GiWa_1Nnq0pm76h0og82fcx6_1RuidueVGvykAxmiS6pSTLSpX7lJHjoPXY7DS3sTVlVXswttRbXb4c3xAmcVjypLhuk5TuaLslq7Hh3rY1OWonkjIazhVKbhHfd_0dOkO6w_1zddNz6CBThTWvG_0M6xbROmtpXa9t6v2Fc5eU7MOvpc5FqU5zYGsdf8FUOjF6A8cOl_13nCr3idFhzVSo3eOKBqPTBalSVSV8Jx6plVNpsdEV0YgW2DKbSmya_0t34WlzL9TeXUHqxPR2BPJ2YStHXpRbteqzf92UP_1Kl4bsmLWp_0220lSeR_0PpKh604tNq89mxHmGhEwe0SVeiukRlslo8XFte9JIkWnvppeUTdIIEgl8EDe_1Vs7MXlxm8IqNMk_16hyVstjHhIfWurVbZaTP0sDJVt5kFZRIDhRYbpUb_08YuFrFBhzKMPSBA5zXjYNbiCf_0ZAiT8HTgIV5If83eOShMBvVtwMsDn3BhULho_16SBVzn4AU3fqdQxJc4a2URHx3hTyEhuAanS_0jGHjXFEojYiyyWFItFnOVNz1v_0lh6T4Te816CfNG44bQr_0_1VPL38E7ziDJxXMcxTOPclxI77VVK0J9xyubulAgxfMc3fvB_0wFCDRRxgZz5LWYC2q0Qm0UQLjN9RD1AYouqJyjNiXab9zFNuf11dHKHCauAiQS5sKK_02QXDFB9qgxUCRGl_0qZo5hgGAeeczvi9eiz_1xvpZuJvu_0mT_0JXLatohdgcBvCseHGog08Dly4_0ICA98AcZwDwFyzHHx3NhviTIcDk9lcwuWMH5jhrKv6OZc_1xF8uemGO5FDxgCYLxboCIQPQHyl5lBT


#ifndef SPL_OPER_INSTANCE_DRYHEATEVENT_H_
#define SPL_OPER_INSTANCE_DRYHEATEVENT_H_

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

#define MY_OPERATOR DryHeatEvent$OP
#define MY_BASE_OPERATOR DryHeatEvent_Base
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
#endif // SPL_OPER_INSTANCE_DRYHEATEVENT_H_

