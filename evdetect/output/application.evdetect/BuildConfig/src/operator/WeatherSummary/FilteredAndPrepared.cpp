// eJzNVMuyojAQrfyJNTULnamSgIrKzvcTdERlvBsqSpR4gSAEFL9_0EB_1X57i9wCaHPqc7ndPxXSvrYQsxQh1kSVIzcBaMeoAHMH4F8COb5eKPRS7mqri7NaJGY7D6rMhVo7JXtN4iVEd0XQvK225Vh2pFkbuCMBK3vp_1Lh5_0jar4wkpnRmuhQRIEOt7m9tdTGFbhCkwGZN6fWqDPOIa_06HGuljw_1R2utwNnYnsDcsVD8iZhKlVR8WfHNYXZpTZYjybaXF2pulzlvlTljXsuaPJzVOjzWag8ZeQX3iw5k5DGhT7kKrrolFQYV_15pHO96NorPNKLu_0O5Em7WR548l8qCpvFql8MSl21A9duvDdNDMuw5qwHOi_10g7Xdq8VV1iJ_0PVbnm0ZR83rtxUxrq6XZYlexEXF12KCVYXlaWsFBc8fvSsV9Sdmse9GhWghEYBH2EwJ12JekpUURywkgwfgnmPAEyz3B8k_0wwh0GOJPamPOZh5HtI8MmDrel3qfvogXmcGhghheMMxBDwKEOPnjg4ATiUu9S8Xe0ASDASxwLQAn4LLFzjRoYePFeibMCdO5jL0zwMbExIA4T84Bh2wXn7hh469IYvwCuh30_18LBMLIvMkecfWLwItsQx2hgZsW4drzyMr3_0oLsZGz6HsGmwFPrvGDj2ljz39rrYFdtzd8tO_08uDk2TNwMUt2hZl_0RUlnXhzCReK4vBW4o8QiN2d24Z6BW_1Yh9kTpOM3XLB6k08n8pX6lHvmZ1O9UMrEZcLwqQ9wObGIQFv1XUpISJLlS4_1p9SZIRMyUJ79z0MV_1hLt_1ZgoecXCoJycfJX4QkQe_0T5F5s6pRAuEtw_0h0_1jxPxpt1ftb2ekevTjpe3Ao_0sk9TDVL2V_0WKcJB5n8I3ChZDOxPP6DyBWEL1


#include "./FilteredAndPrepared.h"
using namespace SPL::_Operator::WeatherSummary;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator::WeatherSummary
#define MY_BASE_OPERATOR FilteredAndPrepared_Base
#define MY_OPERATOR FilteredAndPrepared$OP





void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{
   IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);
   if (! (1) ) 
       return;
   { OPort0Type otuple(iport$0.get_stationCode(), iport$0.get_observationTime(), iport$0.get_temp(), ((lit$1 * iport$0.get_temp()) + lit$0), (::SPL::Functions::Math::exp(((lit$5 * iport$0.get_dewpoint()) / (lit$4 + iport$0.get_dewpoint()))) / ::SPL::Functions::Math::exp(((lit$3 * iport$0.get_temp()) / (lit$2 + iport$0.get_temp())))), iport$0.get_dewpoint(), iport$0.get_windHeadingDegrees(), iport$0.get_windSpeedKnots(), iport$0.get_windGustKnots()); submit (otuple, 0);
 }
   
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port) 
{
   forwardWindowPunctuation(punct);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("WeatherSummary::FilteredAndPrepared",&initer));
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



