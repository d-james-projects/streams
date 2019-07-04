// eJzVlN1O6kAQx7O3PsXGnBhIDGyL8qEeE4QiaqEiCOhNU_0jYbm27pd0CxfjuZ1ukB_1U8wHF70_1nPZDo7v5lGgVuKOXUpT87OWnHEmYckRMQjo8NSqcyTAMpXcLsyk7GiWa_1Nnq0pm76h0og82fcx6_1RuidueVGvykAxmiS6pSTLSpX7lJHjoPXY7DS3sTVlVXswttRbXb4c3xAmcVjypLhuk5TuaLslq7Hh3rY1OWonkjIazhVKbhHfd_0dOkO6w_1zddNz6CBThTWvG_0M6xbROmtpXa9t6v2Fc5eU7MOvpc5FqU5zYGsdf8FUOjF6A8cOl_13nCr3idFhzVSo3eOKBqPTBalSVSV8Jx6plVNpsdEV0YgW2DKbSmya_0t34WlzL9TeXUHqxPR2BPJ2YStHXpRbteqzf92UP_1Kl4bsmLWp_0220lSeR_0PpKh604tNq89mxHmGhEwe0SVeiukRlslo8XFte9JIkWnvppeUTdIIEgl8EDe_1Vs7MXlxm8IqNMk_16hyVstjHhIfWurVbZaTP0sDJVt5kFZRIDhRYbpUb_08YuFrFBhzKMPSBA5zXjYNbiCf_0ZAiT8HTgIV5If83eOShMBvVtwMsDn3BhULho_16SBVzn4AU3fqdQxJc4a2URHx3hTyEhuAanS_0jGHjXFEojYiyyWFItFnOVNz1v_0lh6T4Te816CfNG44bQr_0_1VPL38E7ziDJxXMcxTOPclxI77VVK0J9xyubulAgxfMc3fvB_0wFCDRRxgZz5LWYC2q0Qm0UQLjN9RD1AYouqJyjNiXab9zFNuf11dHKHCauAiQS5sKK_02QXDFB9qgxUCRGl_0qZo5hgGAeeczvi9eiz_1xvpZuJvu_0mT_0JXLatohdgcBvCseHGog08Dly4_0ICA98AcZwDwFyzHHx3NhviTIcDk9lcwuWMH5jhrKv6OZc_1xF8uemGO5FDxgCYLxboCIQPQHyl5lBT


#include "./DryHeatEvent.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR DryHeatEvent_Base
#define MY_OPERATOR DryHeatEvent$OP




static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("DryHeatEvent",&initer));
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
    if (((iport$0.get_tempInF() > lit$1) && (iport$0.get_relativeHumidity() < lit$0))) 
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



