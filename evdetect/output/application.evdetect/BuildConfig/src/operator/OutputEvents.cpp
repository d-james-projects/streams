// eJzVVF1zokgUrX6dX0FN5cFUpZSPxA_12o0oFYxRFAyPqC9VCB5oAjdAoOLX_1fVvIZI2T3dp9XHig_0t6_0p0_1few5ZEjZTFEKKSQxDWR7lsUNJCgTAs1cCX5vNFi0T1BqgydEtV6ruvfZnvq6e5lDDGb_1xFzkZzSZ8qFjtjmjwy11pC1pZmrYwl_06T59m38ainp7M1aYt7x9M6eXdiPPFBEgxzq33o8cM40G1B1PIgmg5PNj8shcA0dnu1Y6XTsbOxxkZ34xT9COLE5lXSX_1RWXY_1XR4VQdDun7nwfTMum_1_1WaqsOoBv2lr4_1iPdGwBWfLwE8P862EBxQbnVDDYo_0WEWJMn71eW7XmarrSPCgpxBzwNu8lvohcdbYu46jYsku58Ul68JfFg4n8teWWiWILL_1pjoT3Nd8_1zQV5AUXW7a0VR_0_0rWXK2P_0XKYP7T728D7hvY2HyDdGgvYFrDIH_1fPj16UvZSlrhyin_0inM6MtmkNBOxnZZG8UT5q54fuprhjFRJsdFqeNMt3m8LWvWfeLweJcL4CMQopuKI6QQVMce8BYaLKcZp8sBBBieiOB_0_0rL18kcx1QSQRUS6tBFRPwpIn3EBKDlkwi12BLBKINuhOPWkaSvWQId1EIHF1Hk0JYLKQQxidFZYWed4YSk7yT_0f8MDGKSVW75_14djjkDijXHWX8yjYUKKEw_04NzbjfOFmuEpXLmOMyWTbZHll2WMsoMn_1sb7y1pOkhah9ZykfpCoY5yhq3VYzsMpQeKteeixq3d1w1yNtfKg7XSvj05Doly1m_0qyfY_0Ft2Z6RGdYe3g4T6I7Lz_1vgCgAg_0kAQ0T0L065swKjYMbkhcdMfk077nrujfvYQEMllxFEXJh8VTPHpf17_0pAxrnEXYxLd8TLjomhAGfwYU2d8SxO0bQZUcryEsRyi4SRoKQO40JvQw_05hmtYr8DdEAxBX_1ZhAfkWp3_10ZsgYvKQamCT_0fsCXPhooHcnVCOuChq3daFRt_1Df1n4mmYsp_1EA99_16fIK9lxNrxJwkxAz6


#include "./OutputEvents.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR OutputEvents_Base
#define MY_OPERATOR OutputEvents$OP





void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{
   IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);
   if (! (1) ) 
       return;
   { OPort0Type otuple(iport$0.get_event(), iport$0.get_weatherValues().get_stationCode(), state$timeString); submit (otuple, 0);
 }
   
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port) 
{
   forwardWindowPunctuation(punct);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("OutputEvents",&initer));
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
    state$timeString = lit$3;
    SPLAPPTRC(L_DEBUG, "Variable: state$timeString Value: " << state$timeString,SPL_OPER_DBG);
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
    const SPL::timestamp id$ts = ::SPL::Functions::Time::createTimestamp(iport$0.get_weatherValues().get_observationTime(), lit$0);
    state$timeString = ::SPL::Functions::String::substring(::SPL::Functions::Time::ctime(id$ts), lit$1, lit$2);
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
    opstate << state$timeString;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$timeString;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$timeString;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$timeString;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$timeString = lit$3;
    SPLAPPTRC(L_DEBUG, "Variable: state$timeString Value: " << state$timeString,SPL_OPER_DBG);
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



