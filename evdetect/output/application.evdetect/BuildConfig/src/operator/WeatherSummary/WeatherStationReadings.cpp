// eJzNWG1T4kgQrnz1V3Bb_0wHuVEhmwtvdbhWIL6AgAq63_0yUVySDRkLCZUUTL_136TySQkzEQRd6sO_1UB6np7ufrrTMzSeO_1s_0ckxie67p1OtH9_06YeL6iKiX6B5RP_0_1tF_0k_0Wc1Rsos7CWh4ent_1cNbpNq_1HUuzodPwwH3u3BfW3RaRqlYaPX7WjaoLzAGMCHu0ET6oMusY4vjVLZvDdKC_1DkTK5GjdKNeXluXx99cwbtETD95mR0Vf3xo_0w8GaXvo_1ll6bSvN38sydTuHbf6Op72m5Ppt17fhCe9Y3Lyc2KoTq390Lran34SfPS7w4XWO3BOz_1pW_1_1QOktM7jJfjp35j0TyiIVxKlJZ_0r10FvfbdYcOpTY501L3tPY3hrNMaPjYMFZAxAPjS6dvd2_17tGJzYF234_1dw5bHcah2YD2j8PBt3BNblonf27bNpnh4NG56xrNjqNVqc2QheBxaqCiUnQZ8cbH3gWUob9s3rdx8S33Zv0g6o4NvkMy1zBu8Yje8YVbJeUYfIrB1c4mKDZPFyeOJ5JgJZ_04OjIFwstNkDXOHruI4xj22o5_0TWE6iUOXQznCFmvY9UIe4JMKyYhC61F6ON7TF6HAkWH7FspzSuTqRKZliSUSUCaiJAHiUxPmmeSsiCpCJKqIKnJPC3FsMicKvNe1UQcEEVQpqqLuLIMV5EJq6JyTRBpsiRoqogTo9DEKDRZFJoYhSaLQquIuKoMJ0YBxFwAVcgiEGMAYgwAiiIxAiCLAFQSNRjXalUmlFUUFKOAqkQZinFAINtPjASKkUBZJHCVi9hqMo5YuSZ760oC9bqYDV0TRSAlUopTb4aK1C9kzrBpzWy3uPD8Ozw3x6iIHixE0JgULZOYiuu5KDgTg5PRnnt_03F02OnIUW_1HZkfq8k6OfJB852wpafIsayX3Jsbb1NwOljgu_0pCaX_0MHAl7TkUnAMcDlIyoOGz_0UwKWetnS_1oyYWwkfOVcmqFt22_0VkmtBU2aL1TDhbHnUhEL3LEx_0SdFwdeAhECVXkPa7sSjqvU6Q7ALCZVi_0sywVAndoMeuScbTPE_1E_1g0ihm8uzq8x8h_1YLvnCLrNeK4Tm7Ukunxf3PPAcB0UP2H5C_0bQjBepa2IsLhRzbKPg8x9_1Y1sn8renvmyQf9uhC7q9wJ5V7FH3W05yxAVhTS_1CZKKTlzJrO8Ct_06LEfMHtDQquKKtMSorsQLM1GUHkU6Y0ibD56G37zXape_104_1RrdrtFrGdGrMZgbGu6vgw7yrZSnNq1cmKyJaSkNEubBwngWf2OZlw0IOXj4jeNM82mc2LuW4ingAlS0qN2U5rt1qdu2mugU3gueOMTajyHjj3U2X2td6PYAINuM6qxXW_0GdhZME1tZD7wttY6k2T_0rm3epLY_0AhVmiYz_1ixIVi7xhvoLqdPAOnWbUaivKISyKKR_0762eRJsv7678he1a2xa8Vt6i4AODcfIqr_1RoTl2AjxmrFXJ_1cMaq2UWXOOekWWZ3iewcJy2C0npqkYPR23bD66asn8XH84dd09ZdS5_1kSXOZ5wa79AV1cO_1apO1a6JFqrlbel9S9MOz1c2_1b6gDSlyId5IdJ1LO6XoRKchO_1r6D83q6zedr5vT72OJ_1dqcpwN7fSjzWSFgu5P0OPK1k96p2E_1jL3AoOxd1WZd_0_1vZtem7zW2bWdgm5snsxhVLEydhOl7_0m8hVlLdzKGovGFwOoYUQzWiONXBnrM6wysMX2zLMPxIa2CWY6Zf6Q0bM57B3kXMXqo5vOy87Cj0x2T6V4uyGgGWFG_19V_0b_1bfiqzOiP2nCUSH1nQ82V_12uTqmgwGE0_1vVXQbLgZDTPV5FggUoomoGy4uRpOqunRQIRmqOh69DaczUBZlu991LUdx6Zpw0o0UUzNFSKdcBIaNHV_0SLfQjY_1QG1rxoDNQZP301PXIW0rhJDVQCXrcJhoBjhbQf_11LPnP


#include "./WeatherStationReadings.h"
using namespace SPL::_Operator::WeatherSummary;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator::WeatherSummary
#define MY_BASE_OPERATOR WeatherStationReadings_Base
#define MY_OPERATOR WeatherStationReadings$OP





void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{
   IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);
   if (! (1) ) 
       return;
   { OPort0Type otuple(state$locCode, state$obsTime, state$temp, state$dewp, state$press, state$wHeading, state$wSpeed, state$wGust); submit (otuple, 0);
 }
   
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port) 
{
   forwardWindowPunctuation(punct);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("WeatherSummary::WeatherStationReadings",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator()  {
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    initRTC(*this, lit$1, "lit$1");
    initRTC(*this, lit$2, "lit$2");
    initRTC(*this, lit$3, "lit$3");
    initRTC(*this, lit$4, "lit$4");
    initRTC(*this, lit$5, "lit$5");
    initRTC(*this, lit$6, "lit$6");
    initRTC(*this, lit$7, "lit$7");
    initRTC(*this, lit$8, "lit$8");
    initRTC(*this, lit$9, "lit$9");
    initRTC(*this, lit$10, "lit$10");
    initRTC(*this, lit$11, "lit$11");
    initRTC(*this, lit$12, "lit$12");
    initRTC(*this, lit$13, "lit$13");
    initRTC(*this, lit$14, "lit$14");
    initRTC(*this, lit$15, "lit$15");
    initRTC(*this, lit$16, "lit$16");
    initRTC(*this, lit$17, "lit$17");
    initRTC(*this, lit$18, "lit$18");
    initRTC(*this, lit$19, "lit$19");
    initRTC(*this, lit$20, "lit$20");
    initRTC(*this, lit$21, "lit$21");
    initRTC(*this, lit$22, "lit$22");
    initRTC(*this, lit$23, "lit$23");
    initRTC(*this, lit$24, "lit$24");
    initRTC(*this, lit$25, "lit$25");
    initRTC(*this, lit$26, "lit$26");
    initRTC(*this, lit$27, "lit$27");
    initRTC(*this, lit$28, "lit$28");
    initRTC(*this, lit$29, "lit$29");
    initRTC(*this, lit$30, "lit$30");
    initRTC(*this, lit$31, "lit$31");
    initRTC(*this, lit$32, "lit$32");
    initRTC(*this, lit$33, "lit$33");
    initRTC(*this, lit$34, "lit$34");
    initRTC(*this, lit$35, "lit$35");
    initRTC(*this, lit$36, "lit$36");
    initRTC(*this, lit$37, "lit$37");
    initRTC(*this, lit$38, "lit$38");
    initRTC(*this, lit$39, "lit$39");
    initRTC(*this, lit$40, "lit$40");
    initRTC(*this, lit$41, "lit$41");
    initRTC(*this, lit$42, "lit$42");
    initRTC(*this, lit$43, "lit$43");
    initRTC(*this, lit$44, "lit$44");
    initRTC(*this, lit$45, "lit$45");
    initRTC(*this, lit$46, "lit$46");
    initRTC(*this, lit$47, "lit$47");
    initRTC(*this, lit$48, "lit$48");
    initRTC(*this, lit$49, "lit$49");
    initRTC(*this, lit$50, "lit$50");
    initRTC(*this, lit$51, "lit$51");
    initRTC(*this, lit$52, "lit$52");
    initRTC(*this, lit$53, "lit$53");
    state$locCode = lit$46;
    SPLAPPTRC(L_DEBUG, "Variable: state$locCode Value: " << state$locCode,SPL_OPER_DBG);
    state$obsTime = lit$47;
    SPLAPPTRC(L_DEBUG, "Variable: state$obsTime Value: " << state$obsTime,SPL_OPER_DBG);
    state$temp = lit$48;
    SPLAPPTRC(L_DEBUG, "Variable: state$temp Value: " << state$temp,SPL_OPER_DBG);
    state$dewp = lit$49;
    SPLAPPTRC(L_DEBUG, "Variable: state$dewp Value: " << state$dewp,SPL_OPER_DBG);
    state$press = lit$50;
    SPLAPPTRC(L_DEBUG, "Variable: state$press Value: " << state$press,SPL_OPER_DBG);
    state$wSpeed = lit$51;
    SPLAPPTRC(L_DEBUG, "Variable: state$wSpeed Value: " << state$wSpeed,SPL_OPER_DBG);
    state$wHeading = lit$52;
    SPLAPPTRC(L_DEBUG, "Variable: state$wHeading Value: " << state$wHeading,SPL_OPER_DBG);
    state$wGust = lit$53;
    SPLAPPTRC(L_DEBUG, "Variable: state$wGust Value: " << state$wGust,SPL_OPER_DBG);
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("01"));
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}

void MY_BASE_OPERATOR::tupleLogic(Tuple const & tuple, uint32_t port) {
    IPort0Type const & iport$0 = static_cast<IPort0Type const  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
{
    SPL::rstring id$obsData = lit$0;
    state$locCode = lit$1;
    state$obsTime = lit$2;
    state$temp = lit$3;
    state$dewp = lit$4;
    state$press = lit$5;
    state$wSpeed = lit$6;
    state$wHeading = lit$7;
    state$wGust = lit$8;
    const SPL::list<SPL::rstring > id$stationInfo = ::SPL::Functions::String::regexMatch(iport$0.get_rawObservation(), lit$9);
    if ((::SPL::Functions::Collections::size(id$stationInfo) > lit$10)) 
        {
            id$obsData = (id$stationInfo.at(lit$12) + lit$11);
            state$locCode = id$stationInfo.at(lit$13);
            const SPL::rstring id$ymdhms = (id$stationInfo.at(lit$15) + lit$14);
            const SPL::timestamp id$ts = ::SPL::Functions::Time::toTimestamp(SPL::BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ::YYYY_MM_DD_hh_mm_ss, id$ymdhms, lit$16);
            state$obsTime = ::SPL::Functions::Time::getSeconds(id$ts);
        }
    const SPL::list<SPL::rstring > id$temp_dewpoint = ::SPL::Functions::String::regexMatch(id$obsData, lit$17);
    if ((::SPL::Functions::Collections::size(id$temp_dewpoint) > lit$18)) 
        {
            state$temp = ::SPL::spl_cast<SPL::float32, SPL::rstring >::cast(id$temp_dewpoint.at(lit$19));
            if ((id$temp_dewpoint.at(lit$21) == lit$20)) 
                state$temp = -state$temp;
            if ((::SPL::Functions::Collections::size(id$temp_dewpoint) > lit$22)) 
                {
                    state$dewp = ::SPL::spl_cast<SPL::float32, SPL::rstring >::cast(id$temp_dewpoint.at(lit$23));
                    if ((id$temp_dewpoint.at(lit$25) == lit$24)) 
                        state$dewp = -state$dewp;
                }
        }
    const SPL::list<SPL::rstring > id$wind = ::SPL::Functions::String::regexMatch(id$obsData, lit$26);
    if ((::SPL::Functions::Collections::size(id$wind) > lit$27)) 
        {
            if ((id$wind.at(lit$29) != lit$28)) 
                state$wHeading = ::SPL::spl_cast<SPL::int16, SPL::rstring >::cast(id$wind.at(lit$30));
            else
                state$wHeading = lit$31;
            state$wSpeed = ::SPL::spl_cast<SPL::int16, SPL::rstring >::cast(id$wind.at(lit$32));
            state$wGust = state$wSpeed;
            const SPL::int32 id$unitIndex = SPL::int32(::SPL::Functions::Collections::size(id$wind) - lit$33);
            if ((::SPL::Functions::Collections::size(id$wind) > lit$34)) 
                state$wGust = ::SPL::spl_cast<SPL::int16, SPL::rstring >::cast(id$wind.at(lit$35));
            if ((id$wind.at(id$unitIndex) == lit$36)) 
                {
                    state$wSpeed = ::SPL::spl_cast<SPL::int16, SPL::float64 >::cast((::SPL::spl_cast<SPL::float64, SPL::int16 >::cast(state$wSpeed) * lit$37));
                    state$wGust = ::SPL::spl_cast<SPL::int16, SPL::float64 >::cast((::SPL::spl_cast<SPL::float64, SPL::int16 >::cast(state$wGust) * lit$38));
                }
        }
    const SPL::list<SPL::rstring > id$baroA = ::SPL::Functions::String::regexMatch(id$obsData, lit$39);
    if ((::SPL::Functions::Collections::size(id$baroA) > lit$40)) 
        state$press = ::SPL::spl_cast<SPL::int16, SPL::float64 >::cast((::SPL::spl_cast<SPL::float64, SPL::rstring >::cast(id$baroA.at(lit$42)) * lit$41));
    else
        {
            const SPL::list<SPL::rstring > id$baroQ = ::SPL::Functions::String::regexMatch(id$obsData, lit$43);
            if ((::SPL::Functions::Collections::size(id$baroQ) > lit$44)) 
                state$press = ::SPL::spl_cast<SPL::int16, SPL::rstring >::cast(id$baroQ.at(lit$45));
        }
}

}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::punctPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    {
        punctNoPermitProcessRaw(punct, port);
    }
}

void MY_BASE_OPERATOR::punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    switch(punct) {
    case Punctuation::WindowMarker:
        punctLogic(punct, port);
        process(punct, port);
        break;
    case Punctuation::FinalMarker:
        punctLogic(punct, port);
        {
            process(punct, port);
            bool forward = false;
            {
                AutoPortMutex $apm($fpMutex, *this);
                $oportBitset.reset(port);
                if ($oportBitset.none()) {
                    $oportBitset.set(1);
                    forward=true;
                }
            }
            if(forward)
                submit(punct, 0);
            return;
        }
    case Punctuation::DrainMarker:
    case Punctuation::ResetMarker:
    case Punctuation::ResumeMarker:
        break;
    case Punctuation::SwitchMarker:
        break;
    case Punctuation::WatermarkMarker:
        break;
    default:
        break;
    }
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    switch(port) {
    case 0:
        punctNoPermitProcessRaw(punct, port);
        break;
    }
}



void MY_BASE_OPERATOR::checkpointStateVariables(NetworkByteBuffer & opstate) const {
    opstate << state$locCode;
    opstate << state$obsTime;
    opstate << state$temp;
    opstate << state$dewp;
    opstate << state$press;
    opstate << state$wSpeed;
    opstate << state$wHeading;
    opstate << state$wGust;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$locCode;
    opstate >> state$obsTime;
    opstate >> state$temp;
    opstate >> state$dewp;
    opstate >> state$press;
    opstate >> state$wSpeed;
    opstate >> state$wHeading;
    opstate >> state$wGust;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$locCode;
    ckpt << state$obsTime;
    ckpt << state$temp;
    ckpt << state$dewp;
    ckpt << state$press;
    ckpt << state$wSpeed;
    ckpt << state$wHeading;
    ckpt << state$wGust;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$locCode;
    ckpt >> state$obsTime;
    ckpt >> state$temp;
    ckpt >> state$dewp;
    ckpt >> state$press;
    ckpt >> state$wSpeed;
    ckpt >> state$wHeading;
    ckpt >> state$wGust;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$locCode = lit$46;
    SPLAPPTRC(L_DEBUG, "Variable: state$locCode Value: " << state$locCode,SPL_OPER_DBG);
    state$obsTime = lit$47;
    SPLAPPTRC(L_DEBUG, "Variable: state$obsTime Value: " << state$obsTime,SPL_OPER_DBG);
    state$temp = lit$48;
    SPLAPPTRC(L_DEBUG, "Variable: state$temp Value: " << state$temp,SPL_OPER_DBG);
    state$dewp = lit$49;
    SPLAPPTRC(L_DEBUG, "Variable: state$dewp Value: " << state$dewp,SPL_OPER_DBG);
    state$press = lit$50;
    SPLAPPTRC(L_DEBUG, "Variable: state$press Value: " << state$press,SPL_OPER_DBG);
    state$wSpeed = lit$51;
    SPLAPPTRC(L_DEBUG, "Variable: state$wSpeed Value: " << state$wSpeed,SPL_OPER_DBG);
    state$wHeading = lit$52;
    SPLAPPTRC(L_DEBUG, "Variable: state$wHeading Value: " << state$wHeading,SPL_OPER_DBG);
    state$wGust = lit$53;
    SPLAPPTRC(L_DEBUG, "Variable: state$wGust Value: " << state$wGust,SPL_OPER_DBG);
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return true;
}

void MY_BASE_OPERATOR::resetToInitialStateRaw() {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->resetToInitialState();
    }
    resetStateVariablesToInitialState();
}

void MY_BASE_OPERATOR::checkpointRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->checkpoint(ckpt);
    }
    checkpointStateVariables(ckpt);
}

void MY_BASE_OPERATOR::resetRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->reset(ckpt);
    }
    resetStateVariables(ckpt);
}



