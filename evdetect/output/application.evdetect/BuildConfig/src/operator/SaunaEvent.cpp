// eJzVlG1P4kAQx7Nv_1RQbczGQGNgW5UHvLkEoohQqgoC_0aQod261tt7RboBq_1_020L9FDvA5zbN53_1TKaz85tpFLilmFOX8uTiohVHnHlIQkQ8Mjoulco8CaB8BbdrM5komvXS7Nua8jowVBqRR_1suZp3_0LXHb02pNHpHhPNElNUnGujSonAX3_1Ydup6GF_1RmrysuFpdbi_0u3ohjiB04qn1VWDtHxH0yVZjR2v13rVSSuRnPFovlRq07DXXTxOu6P642LT9Awa6ERhzbvGpG4RrbORNvXaa32wdHpJyT7_0XOpClOo0h7bW8ZdMpVOjP3TscDV4qtArTkc1V6VygyceiErvrUZVmQ6UcKJaRqXNxldEJ1Zgy2Aq_1Vnie5sncSnTf62c28PN_0Rjs2dRMgrYuPWvXG_1VmML8fXMUbQ1bM_0qzdVprK03gyW8fDVnxebT451gMsdeKANu1KVJeoTNbL_02vLi56TRGuvvLR8gs6QQPCDoNGdenHx7DKDV2SUadI_1NHmrhREPqW9ttcpWi6mfhaGyzTwoiwgwvMgwPeqX1yx8iQJjAWVYmcBhwcumwQ3kMx9S5Cl4GrAwL_0T_1Bo88FGaj_0naExaHPuFAo7OovWcB1Dl5w43cKRfwbZ60s4pMT_1CEkBNfgdAXd2KOmWII8lhSLRZzlTc9b_1pYek_0E3fNCg7zRuOG0K_1vVdy9_1DO80gycVLHMVzj3JcSO_01VStCfcdrm7pQIMXLHN370fsRQg0UcYGc_0S1mAtqvEJtHEK4yfUw9QGKLqmcozYn2m7ebptz_0PDq5w4R1wESCXFhT3_0yCYYoPtcEKAaI0v1TNHKMAwOz5jB_0K1_0JPfKilm8m_0buZ3Ipdtq_0gFGNyGcGK4sWgDjwMXfu4g4AMwpxkA_1AnL6a6j2RB_1MASY3P4MJnfswZxmTcVfsRw4_1mI5EHMsvwUPWIFgvB8gIhD9AdLSGVV


#include "./SaunaEvent.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR SaunaEvent_Base
#define MY_OPERATOR SaunaEvent$OP




static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("SaunaEvent",&initer));
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
    if (((iport$0.get_tempInF() > lit$1) && (iport$0.get_relativeHumidity() > lit$0))) 
        {
            do { SPL::BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm temp = SPL::BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm(iport$0, lit$2); submit (temp, lit$3); } while(0);
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



