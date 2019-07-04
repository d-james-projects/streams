// eJzVk11v2jAYheV_1gqqpIjf54EstF5VIoVAYFEEoGjeRwW_1Aw8SZbcjg188EkkIp43ZTcuNjn2Pn8YmMmCmAYUV5iFm1_0kKZAoEcZOvHQXemaelXbSOwXGjHZNtovM2Xta5LarveuDPbDAf85_1P6MW67vj2s9brtQmFQiaUsljbLgVsqD7qKNEe_0XcFr346LOxaMvZo9x6M3On15Z4NXr4iFG3jjh8mkwna_0_1cOLRnanX3YnW7WgvWa9X5aLvhss3nt9XGr1mqr1K_1Ad9vi6qY_1NxZ0_0ZwExqr7ZaNj_1Xq0GjGNVLKBEcz5pyFrwFVhSCcAricmKhlbMxVJGeAYWbAgomCmLYIVRyEPYMwhSJEnUlHMGONTDfJ5GXOh9zTkoX8Eqyhu5p1yyrZG7v8_0dzROII05Dla2xDQM1fkcCpNTsE_0LH9YeN_1kXciCKRNAOhByRV0ppnTgAJTZSGc8SnEsQm0T26AqQ_1uFJCezYovYMURCYkCNYCupQxOsVC7l1OBcU0JC3AROfWYS4ATieGEQDphFydis21VKfanin_1L5h_0TdNJS5cKWUWSSp1Y8sYV9FnEYXge8MmiQ85uKvOmwrn70PjL_07xh_0_1gRrt786aH18Nx_1YdJBV6vy16RL1zHqolw3Yz4cx4jLKt5IyAx5Q9f2D4rBMsD




#ifndef SPL_OPER_INSTANCE_WEATHERSUMMARY_FILTEREDMISSINGVALUES_H_
#define SPL_OPER_INSTANCE_WEATHERSUMMARY_FILTEREDMISSINGVALUES_H_

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

#define MY_OPERATOR FilteredMissingValues$OP
#define MY_BASE_OPERATOR FilteredMissingValues_Base
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
    
    
    
    SPL::float32 lit$0;
    SPL::float32 lit$1;
    
    
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
#endif // SPL_OPER_INSTANCE_WEATHERSUMMARY_FILTEREDMISSINGVALUES_H_

