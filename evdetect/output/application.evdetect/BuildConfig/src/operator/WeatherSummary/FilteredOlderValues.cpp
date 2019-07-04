// eJzVUsuS2jAQLP0JtZWDfQg2z9r1IVV4eS0sLMVjqXBxCTQGBdlyJIEDXx_1ZPBbisFyTsg_0e8XRr1N0yYnkBDCvKQ8wcp0mZAoEKyNZPAT3k85Z_01S4Cy4VOTHaNxttyXeu5pLbvT7uL7WjIfzxvnuKO69mjWr_1XKRaH1VjKUnm7HrrlyrCnSGvi2VW88ey4tGf_0dFyzl3jyRufNdzZ8GZewcP3x9HE2q7K9Z38fRxO7O6i4s51a0X6rPqjI1cD1V_0_19AS63_0y3V_1ul7Bfb0sq1P86uHdE9G1RcbjQavjkNDVS0jhKwVD8CSSgAOJCYBDa2Yi7WM8AIs2BJQsFAWwQqjkIeQsPiny6dEc84Z4FCXBo240Afkl6A8PpcgtqlgYxqAYea_05T4ONhwnLZqbcJGMSMdJphxHQ0ew4CGRn40kH1LhIDJMM_1c1l17LNFHjVyRASj2cOnNc57Dmv2gLokikCULoEen7JNd85gSQ0H7QcIn_0EBEdTFMQRMhnHKtSERGII67750YqwUZAjzJG51jIBFWoopiGpA2YaN46LAXA5Y9RBEC6IVeXzdZGqsteoin_1LzT9u5qFU2RPjXNE0sReQAzzhvRnikN5TZCJ_1LVTZ_0ypcY1OZjUk4_0cd2GleQ285f7m0Lq_1xGZAmuhmVT5myqCNVJlx3aT4QR4psFO8wnAGGqWP7G0wUNt3




#include "./FilteredOlderValues.h"
using namespace SPL::_Operator::WeatherSummary;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator::WeatherSummary
#define MY_BASE_OPERATOR FilteredOlderValues_Base
#define MY_OPERATOR FilteredOlderValues$OP



void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{
   IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);   
   if ((iport$0.get_observationTime() > SPL::int64(::SPL::Functions::Time::getSeconds(::SPL::Functions::Time::getTimestamp()) - lit$0))) 
       submit(tuple, 0);

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port) 
{
   forwardWindowPunctuation(punct);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("WeatherSummary::FilteredOlderValues",&initer));
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
    addParameterValue ("filter");
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
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return false;
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



