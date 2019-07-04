// eJzVVF1zokgUrX6dX0FN5cFUpZSPxA_12o0oFYxRFAyPqC9VCB5oAjdAoOLX_1fVvIZI2T3dp9XHig_0t6_0p0_1few5ZEjZTFEKKSQxDWR7lsUNJCgTAs1cCX5vNFi0T1BqgydEtV6ruvfZnvq6e5lDDGb_1xFzkZzSZ8qFjtjmjwy11pC1pZmrYwl_06T59m38ainp7M1aYt7x9M6eXdiPPFBEgxzq33o8cM40G1B1PIgmg5PNj8shcA0dnu1Y6XTsbOxxkZ34xT9COLE5lXSX_1RWXY_1XR4VQdDun7nwfTMum_1_1WaqsOoBv2lr4_1iPdGwBWfLwE8P862EBxQbnVDDYo_0WEWJMn71eW7XmarrSPCgpxBzwNu8lvohcdbYu46jYsku58Ul68JfFg4n8teWWiWILL_1pjoT3Nd8_1zQV5AUXW7a0VR_0_0rWXK2P_0XKYP7T728D7hvY2HyDdGgvYFrDIH_1fPj16UvZSlrhyin_0inM6MtmkNBOxnZZG8UT5q54fuprhjFRJsdFqeNMt3m8LWvWfeLweJcL4CMQopuKI6QQVMce8BYaLKcZp8sBBBieiOB_0_0rL18kcx1QSQRUS6tBFRPwpIn3EBKDlkwi12BLBKINuhOPWkaSvWQId1EIHF1Hk0JYLKQQxidFZYWed4YSk7yT_0f8MDGKSVW75_14djjkDijXHWX8yjYUKKEw_04NzbjfOFmuEpXLmOMyWTbZHll2WMsoMn_1sb7y1pOkhah9ZykfpCoY5yhq3VYzsMpQeKteeixq3d1w1yNtfKg7XSvj05Doly1m_0qyfY_0Ft2Z6RGdYe3g4T6I7Lz_1vgCgAg_0kAQ0T0L065swKjYMbkhcdMfk077nrujfvYQEMllxFEXJh8VTPHpf17_0pAxrnEXYxLd8TLjomhAGfwYU2d8SxO0bQZUcryEsRyi4SRoKQO40JvQw_05hmtYr8DdEAxBX_1ZhAfkWp3_10ZsgYvKQamCT_0fsCXPhooHcnVCOuChq3daFRt_1Df1n4mmYsp_1EA99_16fIK9lxNrxJwkxAz6



#ifndef SPL_OPER_INSTANCE_OUTPUTEVENTS_H_
#define SPL_OPER_INSTANCE_OUTPUTEVENTS_H_

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
#include "../type/BeJwrMS62TC1LzSsJqSxILTY0ArODSxJLMvPzYDKZuakALW4PBP.h"

#include <bitset>

#define MY_OPERATOR OutputEvents$OP
#define MY_BASE_OPERATOR OutputEvents_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm IPort0Type;
    typedef SPL::BeJwrMS62TC1LzSsJqSxILTY0ArODSxJLMvPzYDKZuakALW4PBP OPort0Type;
    
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
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::uint32 lit$0;
    SPL::int32 lit$1;
    SPL::int32 lit$2;
    SPL::rstring lit$3;
    
    SPL::rstring state$timeString;
    
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
   MY_OPERATOR() {}
  
   void process(Tuple const & tuple, uint32_t port);
   void process(Punctuation const & punct, uint32_t port);
   
       void getCheckpoint(NetworkByteBuffer & opstate) { checkpointStateVariables(opstate); }
       void restoreCheckpoint(NetworkByteBuffer & opstate) { restoreStateVariables(opstate); }
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_OUTPUTEVENTS_H_

