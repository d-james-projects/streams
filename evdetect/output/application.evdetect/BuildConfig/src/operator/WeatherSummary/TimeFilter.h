// eJzVkktz2jAUhUf_1JJPpwt5g85zE0y5weAUKYXiEKRuPQNegIluuJHDh11c2j5q6hG079sK6ut_0x7tGRESsIYFhRHmLmOC3KFAhURLZ_0iuixULD0q_1YRWC50Y7JvNt9Wm3rfJfXDYNZb7sYj_1v1l_0xx3Xc8e1wf9bqk0qsVSliu7zcitVEd9RdpTz67hrWfH5QPzZ5O6vcLTN7povbPR66SMhetPZk_1zeY0dPPvbJJravWHVne_1Vmg7ajWFVroeuv34fDHGlM2irzg_1fK7Ln111jVlg_1pidF1poHYEklAAcSk4CGVszFRkZ4CRbsCChYKotghVHIQ0hm88_0jjodfHWfBOQMcai2DRlyoT3ZhBcrjCwlil9ozoQEY5sPnLw_0OkyKtbbhMNqTjJHuOo4ExLHlIpPFBS_1IhFQ4iwzRN1PwZCZBS96Smn_159PNO_16DiiSBwtR09Ij5FM98IJIKHNp_0EK_1eEYoqGqVZCCIEI_041iVS4hAHHFdvxRSC7YC_0pQxusBCJlSxhmIakg5gonUbsBIA2Y1xBEB6IVfZYnsrVbaWeMr_1C0_1_17mbxnM9z4RKRNJ4ZxDBvWH_0ROC6vBXL5vr6pC3suXNNJr0Zy93kHO_1dr9NbNZw_0tl9d8DtJCN6PyoVKeOknlwnVX5jdxkshH8Y7CBTBMHdtfsvjRCF




#ifndef SPL_OPER_INSTANCE_WEATHERSUMMARY_TIMEFILTER_H_
#define SPL_OPER_INSTANCE_WEATHERSUMMARY_TIMEFILTER_H_

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

#include "../../type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.h"

#include <bitset>

#define MY_OPERATOR TimeFilter$OP
#define MY_BASE_OPERATOR TimeFilter_Base
#define MY_OPERATOR_SCOPE SPL::_Operator::WeatherSummary

namespace SPL {
namespace _Operator {
namespace WeatherSummary {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW IPort0Type;
    typedef SPL::BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
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
   
}; 

} // namespace WeatherSummary
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_WEATHERSUMMARY_TIMEFILTER_H_

