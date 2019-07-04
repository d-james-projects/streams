// eJzNk1tzokAQhav_1SmofkhcBb5X4JtFodL2Ul1jrCzU6rc4KDDvTSPTX74jRyJqseUzBC01_1Z5rTBx35uZiEL2hbqdSwFke_0mDNCcMA2lwM3uZxlbtpGaLnYSvi2Xu8t19WOy6u77qQ93wwH8vdj_1JC0XM8eVrudVj4_1KCdaF4qb9cAtlgYd4o2xZ5dZ7NlJYecvJqOqvWTjnpg9vfiD51GBKXcxmtxPp2V_159m_1RtHYbvdL7nRLK9Ft1Polveq7i9VLt8_0KzW6Dmn8WnuM_1PG9qk9zqJp3TfMEPG4b9n5XKwpeMykUAsFYyQEuTQhZoxgMRWolUax2xOVq44Ug4J4szYhDKEG3IA4kAezEZxYzW8YAqkRKzmPBJIcIatwZJG5U5RYRLM4uIpDKtuSWSp4mRkOGj5Hh7B_1XXSKHWpnBgRLiXzhJyplFtUmpkRslSznvzQeE7bgQEqDQ8APdwZgAcLfrnE_0FgA2EQQWp3IQ8ck0ia_0qmQWhAr7AjfFzOm9J5yypCIkDeRcaNbw6XZyfmLYYTI26Gk82Ij1nRe23sqv72ngfH0YzedY1S_1ksCPrT9JfC2QmU05mT_1FFLL0vtcgF_1u8gh37DfrZ5s_0HNo9Z_1gIyQp9G5b9Kl9Sb1EW4rsq8E28Sl1G8onACbu9MbP8CK27aCj




#include "./NoDuplicates.h"
using namespace SPL::_Operator::WeatherSummary;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator::WeatherSummary
#define MY_BASE_OPERATOR NoDuplicates_Base
#define MY_OPERATOR NoDuplicates$OP



MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
:
        
            _diff (lit$0)
        
{
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{

    AutoPortMutex apm(_mutex, *this);


    const IPort0Type& iport$0 = static_cast<const IPort0Type&>(tuple);

    // Check to see if this tuple has been seen recently - create the key
    
        double newVal = SPL::Functions::Time::getTimestampInSecs();
    
    ListDataType newValue(KeyType(iport$0.get_stationCode(), iport$0.get_observationTime()), newVal);
    
    TupleMapType::iterator it = _map.find(newValue._key);
    if (it != _map.end()) {
        // We found an old one - Is it still valid?
        if ((newVal - it->second->_value) > _diff) {
            // long enough ago....
            OPort0Type otuple(iport$0); submit (otuple, 0);
 
            _list.push_front(newValue);
            _list.erase(it->second);
            it->second = _list.begin();  // restart the counter
        } else {
            
                // else suppress this one and reset the value
                _list.push_front(newValue);
                _list.erase(it->second);
                it->second = _list.begin();
            
            
        }
    } else {
        // Haven't seen this one
        OPort0Type otuple(iport$0); submit (otuple, 0);

        _list.push_front(newValue);
        _map.insert(make_pair(newValue._key, _list.begin()));
    }

    // Keep the map a reasonable size by cleaning up elements that have expired
    while (!_list.empty()) {
        ListDataType & oldest = *_list.rbegin();
        // Look at the list to see if we should remove it
        if ((newVal - oldest._value) < _diff) 
            break; // list is ordered, no need to continue
        // Remove from the map and the list
        TupleMapType::iterator it = _map.find(oldest._key);
        assert(it != _map.end()); 
        _map.erase(it);  
        _list.pop_back();
    }

    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{
    
    forwardWindowPunctuation(punct);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetCommon()
{
    _list.clear();
    _map.clear();
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetToInitialState()
{
    AutoMutex am(_mutex);
    resetCommon();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::checkpoint(Checkpoint & ckpt) 
{
    AutoMutex am(_mutex);

    
    uint32_t listSize = _list.size();
    ckpt << listSize;

    for (TupleListType::reverse_iterator rit = _list.rbegin(); 
         rit != _list.rend(); rit++) {
        ListDataType & item = *rit;
        item.checkpoint(ckpt);
    }
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::reset(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    resetCommon();

    
    uint32_t listSize = 0;
    ckpt >> listSize;

    ListDataType item;
    for (uint32_t i = 0; i < listSize; i++) {
        item.reset(ckpt);
        _list.push_front(item);
        _map.insert(make_pair(item._key, _list.begin()));
    }
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("WeatherSummary::NoDuplicates",&initer));
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
    addParameterValue ("timeOut", SPL::ConstValueHandle(lit$0));
    addParameterValue ("key");
    addParameterValue ("key");
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



