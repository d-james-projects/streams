// eJzNWG1T4kgQrnz1V3Bb_0wHuVEhmwtvdbhWIL6AgAq63_0yUVySDRkLCZUUTL_136TySQkzEQRd6sO_1UB6np7ufrrTMzSeO_1s_0ckxie67p1OtH9_06YeL6iKiX6B5RP_0_1tF_0k_0Wc1Rsos7CWh4ent_1cNbpNq_1HUuzodPwwH3u3BfW3RaRqlYaPX7WjaoLzAGMCHu0ET6oMusY4vjVLZvDdKC_1DkTK5GjdKNeXluXx99cwbtETD95mR0Vf3xo_0w8GaXvo_1ll6bSvN38sydTuHbf6Op72m5Ppt17fhCe9Y3Lyc2KoTq390Lran34SfPS7w4XWO3BOz_1pW_1_1QOktM7jJfjp35j0TyiIVxKlJZ_0r10FvfbdYcOpTY501L3tPY3hrNMaPjYMFZAxAPjS6dvd2_17tGJzYF234_1dw5bHcah2YD2j8PBt3BNblonf27bNpnh4NG56xrNjqNVqc2QheBxaqCiUnQZ8cbH3gWUob9s3rdx8S33Zv0g6o4NvkMy1zBu8Yje8YVbJeUYfIrB1c4mKDZPFyeOJ5JgJZ_04OjIFwstNkDXOHruI4xj22o5_0TWE6iUOXQznCFmvY9UIe4JMKyYhC61F6ON7TF6HAkWH7FspzSuTqRKZliSUSUCaiJAHiUxPmmeSsiCpCJKqIKnJPC3FsMicKvNe1UQcEEVQpqqLuLIMV5EJq6JyTRBpsiRoqogTo9DEKDRZFJoYhSaLQquIuKoMJ0YBxFwAVcgiEGMAYgwAiiIxAiCLAFQSNRjXalUmlFUUFKOAqkQZinFAINtPjASKkUBZJHCVi9hqMo5YuSZ760oC9bqYDV0TRSAlUopTb4aK1C9kzrBpzWy3uPD8Ozw3x6iIHixE0JgULZOYiuu5KDgTg5PRnnt_03F02OnIUW_1HZkfq8k6OfJB852wpafIsayX3Jsbb1NwOljgu_0pCaX_0MHAl7TkUnAMcDlIyoOGz_0UwKWetnS_1oyYWwkfOVcmqFt22_0VkmtBU2aL1TDhbHnUhEL3LEx_0SdFwdeAhECVXkPa7sSjqvU6Q7ALCZVi_0sywVAndoMeuScbTPE_1E_1g0ihm8uzq8x8h_1YLvnCLrNeK4Tm7Ukunxf3PPAcB0UP2H5C_0bQjBepa2IsLhRzbKPg8x9_1Y1sn8renvmyQf9uhC7q9wJ5V7FH3W05yxAVhTS_1CZKKTlzJrO8Ct_06LEfMHtDQquKKtMSorsQLM1GUHkU6Y0ibD56G37zXape_104_1RrdrtFrGdGrMZgbGu6vgw7yrZSnNq1cmKyJaSkNEubBwngWf2OZlw0IOXj4jeNM82mc2LuW4ingAlS0qN2U5rt1qdu2mugU3gueOMTajyHjj3U2X2td6PYAINuM6qxXW_0GdhZME1tZD7wttY6k2T_0rm3epLY_0AhVmiYz_1ixIVi7xhvoLqdPAOnWbUaivKISyKKR_0762eRJsv7678he1a2xa8Vt6i4AODcfIqr_1RoTl2AjxmrFXJ_1cMaq2UWXOOekWWZ3iewcJy2C0npqkYPR23bD66asn8XH84dd09ZdS5_1kSXOZ5wa79AV1cO_1apO1a6JFqrlbel9S9MOz1c2_1b6gDSlyId5IdJ1LO6XoRKchO_1r6D83q6zedr5vT72OJ_1dqcpwN7fSjzWSFgu5P0OPK1k96p2E_1jL3AoOxd1WZd_0_1vZtem7zW2bWdgm5snsxhVLEydhOl7_0m8hVlLdzKGovGFwOoYUQzWiONXBnrM6wysMX2zLMPxIa2CWY6Zf6Q0bM57B3kXMXqo5vOy87Cj0x2T6V4uyGgGWFG_19V_0b_1bfiqzOiP2nCUSH1nQ82V_12uTqmgwGE0_1vVXQbLgZDTPV5FggUoomoGy4uRpOqunRQIRmqOh69DaczUBZlu991LUdx6Zpw0o0UUzNFSKdcBIaNHV_0SLfQjY_1QG1rxoDNQZP301PXIW0rhJDVQCXrcJhoBjhbQf_11LPnP



#ifndef SPL_OPER_INSTANCE_WEATHERSUMMARY_WEATHERSTATIONREADINGS_H_
#define SPL_OPER_INSTANCE_WEATHERSUMMARY_WEATHERSTATIONREADINGS_H_

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
#include "../../type/BeJwrMSw2NClKLPdPKk4tKkssyczPAwBFJwdU.h"
#include "../../type/BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ.h"

#include <bitset>

#define MY_OPERATOR WeatherStationReadings$OP
#define MY_BASE_OPERATOR WeatherStationReadings_Base
#define MY_OPERATOR_SCOPE SPL::_Operator::WeatherSummary

namespace SPL {
namespace _Operator {
namespace WeatherSummary {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSw2NClKLPdPKk4tKkssyczPAwBFJwdU IPort0Type;
    typedef SPL::BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW OPort0Type;
    
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
    
    
    
    SPL::rstring lit$0;
    SPL::rstring lit$1;
    SPL::int64 lit$2;
    SPL::float32 lit$3;
    SPL::float32 lit$4;
    SPL::int16 lit$5;
    SPL::int16 lit$6;
    SPL::int16 lit$7;
    SPL::int16 lit$8;
    SPL::rstring lit$9;
    SPL::int32 lit$10;
    SPL::rstring lit$11;
    SPL::int32 lit$12;
    SPL::int32 lit$13;
    SPL::rstring lit$14;
    SPL::int32 lit$15;
    SPL::rstring lit$16;
    SPL::rstring lit$17;
    SPL::int32 lit$18;
    SPL::int32 lit$19;
    SPL::rstring lit$20;
    SPL::int32 lit$21;
    SPL::int32 lit$22;
    SPL::int32 lit$23;
    SPL::rstring lit$24;
    SPL::int32 lit$25;
    SPL::rstring lit$26;
    SPL::int32 lit$27;
    SPL::rstring lit$28;
    SPL::int32 lit$29;
    SPL::int32 lit$30;
    SPL::int16 lit$31;
    SPL::int32 lit$32;
    SPL::int32 lit$33;
    SPL::int32 lit$34;
    SPL::int32 lit$35;
    SPL::rstring lit$36;
    SPL::float64 lit$37;
    SPL::float64 lit$38;
    SPL::rstring lit$39;
    SPL::int32 lit$40;
    SPL::float64 lit$41;
    SPL::int32 lit$42;
    SPL::rstring lit$43;
    SPL::int32 lit$44;
    SPL::int32 lit$45;
    SPL::rstring lit$46;
    SPL::int64 lit$47;
    SPL::float32 lit$48;
    SPL::float32 lit$49;
    SPL::int16 lit$50;
    SPL::int16 lit$51;
    SPL::int16 lit$52;
    SPL::int16 lit$53;
    
    SPL::rstring state$locCode;
    SPL::int64 state$obsTime;
    SPL::float32 state$temp;
    SPL::float32 state$dewp;
    SPL::int16 state$press;
    SPL::int16 state$wSpeed;
    SPL::int16 state$wHeading;
    SPL::int16 state$wGust;
    
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

} // namespace WeatherSummary
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_WEATHERSUMMARY_WEATHERSTATIONREADINGS_H_

