// eJzVk11v2jAYheV_1gqqpIjf54EstF5VIoVAYFEEoGjeRwW_1Aw8SZbcjg188EkkIp43ZTcuNjn2Pn8YmMmCmAYUV5iFm1_0kKZAoEcZOvHQXemaelXbSOwXGjHZNtovM2Xta5LarveuDPbDAf85_1P6MW67vj2s9brtQmFQiaUsljbLgVsqD7qKNEe_0XcFr346LOxaMvZo9x6M3On15Z4NXr4iFG3jjh8mkwna_0_1cOLRnanX3YnW7WgvWa9X5aLvhss3nt9XGr1mqr1K_1Ad9vi6qY_1NxZ0_0ZwExqr7ZaNj_1Xq0GjGNVLKBEcz5pyFrwFVhSCcAricmKhlbMxVJGeAYWbAgomCmLYIVRyEPYMwhSJEnUlHMGONTDfJ5GXOh9zTkoX8Eqyhu5p1yyrZG7v8_0dzROII05Dla2xDQM1fkcCpNTsE_0LH9YeN_1kXciCKRNAOhByRV0ppnTgAJTZSGc8SnEsQm0T26AqQ_1uFJCezYovYMURCYkCNYCupQxOsVC7l1OBcU0JC3AROfWYS4ATieGEQDphFydis21VKfanin_1L5h_0TdNJS5cKWUWSSp1Y8sYV9FnEYXge8MmiQ85uKvOmwrn70PjL_07xh_0_1gRrt786aH18Nx_1YdJBV6vy16RL1zHqolw3Yz4cx4jLKt5IyAx5Q9f2D4rBMsD




#include "./FilteredMissingValues.h"
using namespace SPL::_Operator::WeatherSummary;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator::WeatherSummary
#define MY_BASE_OPERATOR FilteredMissingValues_Base
#define MY_OPERATOR FilteredMissingValues$OP



void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{
   IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);   
   if (((iport$0.get_temp() > lit$1) && (iport$0.get_dewpoint() > lit$0))) 
       submit(tuple, 0);

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port) 
{
   forwardWindowPunctuation(punct);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("WeatherSummary::FilteredMissingValues",&initer));
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



