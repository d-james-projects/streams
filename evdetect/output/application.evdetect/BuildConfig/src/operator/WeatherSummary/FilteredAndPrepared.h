// eJzNVMuyojAQrfyJNTULnamSgIrKzvcTdERlvBsqSpR4gSAEFL9_0EB_1X57i9wCaHPqc7ndPxXSvrYQsxQh1kSVIzcBaMeoAHMH4F8COb5eKPRS7mqri7NaJGY7D6rMhVo7JXtN4iVEd0XQvK225Vh2pFkbuCMBK3vp_1Lh5_0jar4wkpnRmuhQRIEOt7m9tdTGFbhCkwGZN6fWqDPOIa_06HGuljw_1R2utwNnYnsDcsVD8iZhKlVR8WfHNYXZpTZYjybaXF2pulzlvlTljXsuaPJzVOjzWag8ZeQX3iw5k5DGhT7kKrrolFQYV_15pHO96NorPNKLu_0O5Em7WR548l8qCpvFql8MSl21A9duvDdNDMuw5qwHOi_10g7Xdq8VV1iJ_0PVbnm0ZR83rtxUxrq6XZYlexEXF12KCVYXlaWsFBc8fvSsV9Sdmse9GhWghEYBH2EwJ12JekpUURywkgwfgnmPAEyz3B8k_0wwh0GOJPamPOZh5HtI8MmDrel3qfvogXmcGhghheMMxBDwKEOPnjg4ATiUu9S8Xe0ASDASxwLQAn4LLFzjRoYePFeibMCdO5jL0zwMbExIA4T84Bh2wXn7hh469IYvwCuh30_18LBMLIvMkecfWLwItsQx2hgZsW4drzyMr3_0oLsZGz6HsGmwFPrvGDj2ljz39rrYFdtzd8tO_08uDk2TNwMUt2hZl_0RUlnXhzCReK4vBW4o8QiN2d24Z6BW_1Yh9kTpOM3XLB6k08n8pX6lHvmZ1O9UMrEZcLwqQ9wObGIQFv1XUpISJLlS4_1p9SZIRMyUJ79z0MV_1hLt_1ZgoecXCoJycfJX4QkQe_0T5F5s6pRAuEtw_0h0_1jxPxpt1ftb2ekevTjpe3Ao_0sk9TDVL2V_0WKcJB5n8I3ChZDOxPP6DyBWEL1



#ifndef SPL_OPER_INSTANCE_WEATHERSUMMARY_FILTEREDANDPREPARED_H_
#define SPL_OPER_INSTANCE_WEATHERSUMMARY_FILTEREDANDPREPARED_H_

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
#include "../../type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h"

#include <bitset>

#define MY_OPERATOR FilteredAndPrepared$OP
#define MY_BASE_OPERATOR FilteredAndPrepared_Base
#define MY_OPERATOR_SCOPE SPL::_Operator::WeatherSummary

namespace SPL {
namespace _Operator {
namespace WeatherSummary {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW IPort0Type;
    typedef SPL::BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy OPort0Type;
    
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
    
    
    
    SPL::float32 lit$0;
    SPL::float32 lit$1;
    SPL::float32 lit$2;
    SPL::float32 lit$3;
    SPL::float32 lit$4;
    SPL::float32 lit$5;
    
    
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
#endif // SPL_OPER_INSTANCE_WEATHERSUMMARY_FILTEREDANDPREPARED_H_

