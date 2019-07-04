// eJzNk01zmzAQhkd_1JdNDezGIZPDHjRI7_1gDsFDsuJ0YxWywbJCzkD_1j1EbZDnUym43Zy6HBg9Er77urZVZ4lDQEJkZQzknQ6VhwLiIkEhJGuPgPdNBqaLDLQvsNwHxVP3XG8ttzluFt6xKG5HiwnW95zh3pyPzebhq8_1PhchdopiGmLv9i774c76vfZYuD_05aWwWsdPctob_0QF9lK3s7N3dt3WarcYgNZ7tKR3YZ6naBV1P_1edNtzsWovwjmfb8VLA5WSmgW6l1uTdpPrVgf9w740GqWLW_0zGhWN5c3bUoU7y8tSN3K7yzzHjw1v8FDE69z3S6dslXvPCSw7xGvW28yekmDw8Fh6hxmfOO5kuCxsSw5hHkDKBpYpgvV9ViWoeCRUftGRP3E6HcqkeYeOCq6VWwMhpC15ClouBZA0J1FKmbbnYp1nZAEa7CKQsJBaRCRBjDOoSFe8acZF7f5_180YUiapqHUeQqGvgCyL4DOlSqy_1XiEGG_1DkHsTtO3ZSm8PUbwlL9f0coivgMtoKDUBvl8nje5hEgodBSFqN3PuiUS0KaoV8JJ5VNtRiwXr0_0TfsO_0tuURlQW9UYE_04wrg1rYUxb1gUQq0T2oZwF55Y_1N44afAUQjxuWl_0LDN5aVWFc_1f9_1SzBxOlqhMmSslhenlv7JIDOo_1lq_1a2CWcyCv451j8RruliS8SVi3Gdy_1HQa_0zbQxe9O6Ubf9i4f0l43XipF_1iODmVX0znFfkhHuXw6Hcr_0QOcvE15FR43pCwI3PCh




#include "./MaxMinTemp.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR MaxMinTemp_Base
#define MY_OPERATOR MaxMinTemp$OP



#include <SPL/Toolkit/Aggregate.h>

#include <SPL/Runtime/Operator/OperatorMetrics.h>





MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
  : MY_BASE_OPERATOR(), _window(*this, 0, ::SPL::DeltaWindowPolicy<ProjectedTupleType*,SPL::int64,&ProjectedTupleType::get_field0>(lit$0), ::SPL::TimeWindowPolicy(lit$1)),
  _partitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitions")) 
{

    _window.registerOnWindowTriggerHandler(this);
    _window.registerOnWindowInitialFullHandler(this);
    _window.registerBeforeTupleEvictionHandler(this);

    
    _partitionCount.setValueNoLock(0);
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR()
{
    // Delete any remaining tuples in the window
     _window.deleteWindowObjects();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::drain() 
{
    SPLAPPTRC(L_DEBUG, "Before draining window", SPL_OPER_DBG);
    _window.drain();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::checkpoint(Checkpoint & ckpt) 
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_TRACE, "Before checkpoint window is: " << _window.toString(), SPL_OPER_DBG);
    _window.checkpoint(ckpt);

    SPLAPPTRC(L_DEBUG, "Before checkpoint the size of _windowFull is: " << _windowFull.size(), SPL_OPER_DBG);
    ckpt << static_cast<uint64_t>(_windowFull.size());
    for (std::tr1::unordered_set<WindowEventType::PartitionType>::const_iterator it = _windowFull.begin(); 
            it != _windowFull.end(); ++it) {
        ckpt << *it;
    }

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::reset(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    _window.reset(ckpt);
    SPLAPPTRC(L_TRACE, "After reset window is: " << _window.toString(), SPL_OPER_DBG);

    _windowFull.clear();
    for (uint64_t partitionCount = ckpt.getUInt64(); partitionCount > 0; --partitionCount) {
        PartitionType partition;
        ckpt >> partition;
        _windowFull.insert(partition);
    }
    SPLAPPTRC(L_DEBUG, "After reset the size of _windowFull is: " << _windowFull.size(), SPL_OPER_DBG);

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetToInitialState()
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_DEBUG, "Resetting window to initial state", SPL_OPER_DBG);
    _window.resetToInitialState();

    SPLAPPTRC(L_DEBUG, "Resetting _windowFull partitions set to initial state", SPL_OPER_DBG);
    _windowFull.clear();

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{

    AutoPortMutex apm(_mutex, *this);

    IPort0Type const & iport$0 = static_cast<IPort0Type const &>(tuple);



    ProjectedTupleType *projected = NULL;
    projected = new ProjectedTupleType(iport$0.get_observationTime(),
iport$0.get_stationCode(),
iport$0.get_tempInF());
    _window.insert(SPL::Creator<WindowType::TupleType>::create(projected));

    _partitionCount.setValueNoLock(_window.getWindowStorage().size());
}



void MY_OPERATOR_SCOPE::MY_OPERATOR::onWindowTriggerEvent(
        WindowEventType::WindowType & window, 
        WindowEventType::PartitionType const & partition) 
{
  SPLAPPTRC(L_DEBUG, window.toString() << " partition " << partition, SPL_OPER_DBG);
    aggregatePartition(window, partition);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::aggregatePartition(
        WindowEventType::WindowType & window, 
        WindowEventType::PartitionType const & partition) 
{
    


    if (_windowFull.find(partition) == _windowFull.end()) {
        SPLAPPTRC(L_DEBUG, "_windowFull.find(partition) can't find", SPL_OPER_DBG);
        return;
    }


    
        WindowType::DataType & data = window.getWindowData(partition);
        if (data.size() == 0) {
    
            submit(Punctuation::WindowMarker, 0);
            return;
        }



    

            SPL::Aggregate::Max<WindowEventType::WindowType,
                                  WindowType::DataType, SPL::float32,
                                  ProjectedTupleType, SPL::float32, bool> Max$maxTemp(window, data, false);
            
                if (Max$maxTemp.needsSeedValue()) {
                    
                    ProjectedTupleType const & projTuple = *Max$maxTemp.getSeedRecord();
                    
                    Max$maxTemp.setSeedValue (projTuple.get_field2());
                }
            
        

            SPL::Aggregate::ArgMax<WindowEventType::WindowType,
                                  WindowType::DataType, SPL::rstring,
                                  ProjectedTupleType, SPL::float32, SPL::rstring, bool> ArgMax$maxTempStation(window, data, false);
            
                if (ArgMax$maxTempStation.needsSeedValue()) {
                    
                    ProjectedTupleType const & projTuple = *ArgMax$maxTempStation.getSeedRecord();
                    
                    ArgMax$maxTempStation.setSeedValue (projTuple.get_field2(), projTuple.get_field1());
                }
            
        

            SPL::Aggregate::ArgMax<WindowEventType::WindowType,
                                  WindowType::DataType, SPL::int64,
                                  ProjectedTupleType, SPL::float32, SPL::int64, bool> ArgMax$maxObservationTime(window, data, false);
            
                if (ArgMax$maxObservationTime.needsSeedValue()) {
                    
                    ProjectedTupleType const & projTuple = *ArgMax$maxObservationTime.getSeedRecord();
                    
                    ArgMax$maxObservationTime.setSeedValue (projTuple.get_field2(), projTuple.get_field0());
                }
            
        

            SPL::Aggregate::Min<WindowEventType::WindowType,
                                  WindowType::DataType, SPL::float32,
                                  ProjectedTupleType, SPL::float32, bool> Min$minTemp(window, data, false);
            
                if (Min$minTemp.needsSeedValue()) {
                    
                    ProjectedTupleType const & projTuple = *Min$minTemp.getSeedRecord();
                    
                    Min$minTemp.setSeedValue (projTuple.get_field2());
                }
            
        

            SPL::Aggregate::ArgMin<WindowEventType::WindowType,
                                  WindowType::DataType, SPL::rstring,
                                  ProjectedTupleType, SPL::float32, SPL::rstring, bool> ArgMin$minTempStation(window, data, false);
            
                if (ArgMin$minTempStation.needsSeedValue()) {
                    
                    ProjectedTupleType const & projTuple = *ArgMin$minTempStation.getSeedRecord();
                    
                    ArgMin$minTempStation.setSeedValue (projTuple.get_field2(), projTuple.get_field1());
                }
            
        

            SPL::Aggregate::ArgMin<WindowEventType::WindowType,
                                  WindowType::DataType, SPL::int64,
                                  ProjectedTupleType, SPL::float32, SPL::int64, bool> ArgMin$minObservationTime(window, data, false);
            
                if (ArgMin$minObservationTime.needsSeedValue()) {
                    
                    ProjectedTupleType const & projTuple = *ArgMin$minObservationTime.getSeedRecord();
                    
                    ArgMin$minObservationTime.setSeedValue (projTuple.get_field2(), projTuple.get_field0());
                }
            
        
        
    
    
        WindowType::DataType::const_iterator it;
        for (it = data.begin(); it != data.end(); it++) {
          
            ProjectedTupleType const & projTuple = **it;
          
            
                Max$maxTemp.process(projTuple.get_field2());
            
                ArgMax$maxTempStation.process(projTuple.get_field2(), projTuple.get_field1());
            
                ArgMax$maxObservationTime.process(projTuple.get_field2(), projTuple.get_field0());
            
                Min$minTemp.process(projTuple.get_field2());
            
                ArgMin$minTempStation.process(projTuple.get_field2(), projTuple.get_field1());
            
                ArgMin$minObservationTime.process(projTuple.get_field2(), projTuple.get_field0());
            
          }
    

        // Populate the tuple
        
          
            ProjectedTupleType const & projTuple = **data.rbegin();
          
        
        
        SPL::BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp otuple(Max$maxTemp(), ArgMax$maxTempStation(), ArgMax$maxObservationTime(), Min$minTemp(), ArgMin$minTempStation(), ArgMin$minObservationTime());
        submit (otuple, 0);



    submit(Punctuation::WindowMarker, 0);
}




    
    void MY_OPERATOR_SCOPE::MY_OPERATOR::onWindowInitialFullEvent(WindowEventType::WindowType & window, 
                                               WindowEventType::PartitionType const & partition) 
    {
        _windowFull.insert (partition);
    }
    

    
    void MY_OPERATOR_SCOPE::MY_OPERATOR::beforeTupleEvictionEvent(WindowEventType::WindowType & window,
                                               WindowEventType::TupleType & tuple,
                                               WindowEventType::PartitionType const & partition)
    {
        delete tuple;
        _partitionCount.setValueNoLock (_window.getWindowStorage().size());
    }
    


static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("MaxMinTemp",&initer));
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



