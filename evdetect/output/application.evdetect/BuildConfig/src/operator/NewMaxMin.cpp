// eJy1VNFymkAUnX31K3YyeYCZVFaSOB3TdoZim0HR0IDp6EsGdYM7yoLsKorx37sQNAHJ9CHt8gAc9tx77tl7YeGivuJkQfi21dJXjAc_0aAAkLhWc1esK34ZY_0Y47cdSzVdXRG2Zis87S3hiOY1mOGxv2BPFue4i8cVe3Nx2zt7YSr90dYUcb6RpbarF2Pbqfo_1rsrBxxwJIEqUz_1Qfum7al943brzZltJ2byOYn75lDTHxtz_0nM5eFgMjdtfSX8zCCyzZ3VmW13jHfx7iH1qaM1oOG_0HaQIVMO5yfD5ZRRGmvOdugG2ZrdbTInD5pVp8aQBR9nmZQuhfKZfgKrujl48R4xGhHsiwxgu2IjTdn2coxMhDFDGgzAIfKyISdn3mTn1ClTiI5ix0J1jB6ynmeMKVqctdQAOK0xNKz4mEQXQU8j9cBT6Isn7Y1aBY5AlKkpRnrXuYP_1ruxsF_0KMnwGyybL8PnZ1jcTWi_0_0wss_0y7LMsySpGt3fEpXOTD8Cis13BRYUjkD_1AQrxZR40wDu4BtHP9j5kIskQvG_1iyhl3XdR7UElbAsnSEBPvh4cqISPJPkGstXYJxxKaS0XMOt0ge5hPCMLLKE3Du5r_0xoATZBnBoceLyoBh6kR8N2Y4WidwQ7xMRCz07wCuYhXfkHUK5_1Qan46HsHpeHzQ_0mwergFei45yxK_1sqAOdFIzeKxmd1Ibeqw6JKv4AsbfMAe


#include "./NewMaxMin.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR NewMaxMin_Base
#define MY_OPERATOR NewMaxMin$OP




static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("NewMaxMin",&initer));
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
    state$currentMax = lit$2;
    SPLAPPTRC(L_DEBUG, "Variable: state$currentMax Value: " << state$currentMax,SPL_OPER_DBG);
    state$currentMin = lit$3;
    SPLAPPTRC(L_DEBUG, "Variable: state$currentMin Value: " << state$currentMin,SPL_OPER_DBG);
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

void MY_BASE_OPERATOR::tupleLogic(Tuple & tuple, uint32_t port) {
    IPort0Type & iport$0 = static_cast<IPort0Type  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
{
    if (((iport$0.get_maxTemp() > state$currentMax) || (iport$0.get_minTemp() < state$currentMin))) 
        {
            state$currentMax = iport$0.get_maxTemp();
            (state$currentMin - iport$0.get_minTemp());
            do { SPL::BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0 temp = SPL::BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0(lit$0, iport$0.get_maxTemp(), iport$0.get_maxTempStation(), iport$0.get_minTemp(), iport$0.get_minTempStation()); submit (temp, lit$1); } while(0);
        }
}

}


void MY_BASE_OPERATOR::processRaw(Tuple & tuple, uint32_t port) {
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
    opstate << state$currentMax;
    opstate << state$currentMin;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$currentMax;
    opstate >> state$currentMin;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$currentMax;
    ckpt << state$currentMin;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$currentMax;
    ckpt >> state$currentMin;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$currentMax = lit$2;
    SPLAPPTRC(L_DEBUG, "Variable: state$currentMax Value: " << state$currentMax,SPL_OPER_DBG);
    state$currentMin = lit$3;
    SPLAPPTRC(L_DEBUG, "Variable: state$currentMin Value: " << state$currentMin,SPL_OPER_DBG);
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



