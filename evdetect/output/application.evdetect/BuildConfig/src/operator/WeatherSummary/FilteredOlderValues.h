// eJzVUsuS2jAQLP0JtZWDfQg2z9r1IVV4eS0sLMVjqXBxCTQGBdlyJIEDXx_1ZPBbisFyTsg_0e8XRr1N0yYnkBDCvKQ8wcp0mZAoEKyNZPAT3k85Z_01S4Cy4VOTHaNxttyXeu5pLbvT7uL7WjIfzxvnuKO69mjWr_1XKRaH1VjKUnm7HrrlyrCnSGvi2VW88ey4tGf_0dFyzl3jyRufNdzZ8GZewcP3x9HE2q7K9Z38fRxO7O6i4s51a0X6rPqjI1cD1V_0_19AS63_0y3V_1ul7Bfb0sq1P86uHdE9G1RcbjQavjkNDVS0jhKwVD8CSSgAOJCYBDa2Yi7WM8AIs2BJQsFAWwQqjkIeQsPiny6dEc84Z4FCXBo240Afkl6A8PpcgtqlgYxqAYea_05T4ONhwnLZqbcJGMSMdJphxHQ0ew4CGRn40kH1LhIDJMM_1c1l17LNFHjVyRASj2cOnNc57Dmv2gLokikCULoEen7JNd85gSQ0H7QcIn_0EBEdTFMQRMhnHKtSERGII67750YqwUZAjzJG51jIBFWoopiGpA2YaN46LAXA5Y9RBEC6IVeXzdZGqsteoin_1LzT9u5qFU2RPjXNE0sReQAzzhvRnikN5TZCJ_1LVTZ_0ypcY1OZjUk4_0cd2GleQ285f7m0Lq_1xGZAmuhmVT5myqCNVJlx3aT4QR4psFO8wnAGGqWP7G0wUNt3




#ifndef SPL_OPER_INSTANCE_WEATHERSUMMARY_FILTEREDOLDERVALUES_H_
#define SPL_OPER_INSTANCE_WEATHERSUMMARY_FILTEREDOLDERVALUES_H_

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

#define MY_OPERATOR FilteredOlderValues$OP
#define MY_BASE_OPERATOR FilteredOlderValues_Base
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
    
    
    
    SPL::int64 lit$0;
    
    
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
#endif // SPL_OPER_INSTANCE_WEATHERSUMMARY_FILTEREDOLDERVALUES_H_

