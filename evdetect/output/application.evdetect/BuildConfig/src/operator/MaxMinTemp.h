// eJzNk01zmzAQhkd_1JdNDezGIZPDHjRI7_1gDsFDsuJ0YxWywbJCzkD_1j1EbZDnUym43Zy6HBg9Er77urZVZ4lDQEJkZQzknQ6VhwLiIkEhJGuPgPdNBqaLDLQvsNwHxVP3XG8ttzluFt6xKG5HiwnW95zh3pyPzebhq8_1PhchdopiGmLv9i774c76vfZYuD_05aWwWsdPctob_0QF9lK3s7N3dt3WarcYgNZ7tKR3YZ6naBV1P_1edNtzsWovwjmfb8VLA5WSmgW6l1uTdpPrVgf9w740GqWLW_0zGhWN5c3bUoU7y8tSN3K7yzzHjw1v8FDE69z3S6dslXvPCSw7xGvW28yekmDw8Fh6hxmfOO5kuCxsSw5hHkDKBpYpgvV9ViWoeCRUftGRP3E6HcqkeYeOCq6VWwMhpC15ClouBZA0J1FKmbbnYp1nZAEa7CKQsJBaRCRBjDOoSFe8acZF7f5_180YUiapqHUeQqGvgCyL4DOlSqy_1XiEGG_1DkHsTtO3ZSm8PUbwlL9f0coivgMtoKDUBvl8nje5hEgodBSFqN3PuiUS0KaoV8JJ5VNtRiwXr0_0TfsO_0tuURlQW9UYE_04wrg1rYUxb1gUQq0T2oZwF55Y_1N44afAUQjxuWl_0LDN5aVWFc_1f9_1SzBxOlqhMmSslhenlv7JIDOo_1lq_1a2CWcyCv451j8RruliS8SVi3Gdy_1HQa_0zbQxe9O6Ubf9i4f0l43XipF_1iODmVX0znFfkhHuXw6Hcr_0QOcvE15FR43pCwI3PCh

#ifndef MaxMinTemp$MyTuple_H
#define MaxMinTemp$MyTuple_H
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Serialization/ByteBuffer.h>
#include <SPL/Runtime/Utility/TimeUtils.h>
#include "../type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h"
#include "../type/BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp.h"

class MaxMinTemp$MyTuple {
public:
  MaxMinTemp$MyTuple() {}


  MaxMinTemp$MyTuple(const MaxMinTemp$MyTuple & o) :
    field0_(o.field0_),
    field1_(o.field1_),
    field2_(o.field2_)
  {}

  MaxMinTemp$MyTuple(
    const SPL::int64 & field0,
    const SPL::rstring & field1,
    const SPL::float32 & field2
  ) :
    field0_(field0),
    field1_(field1),
    field2_(field2)
  {}

  SPL::int64 & get_field0() {
    return field0_;
  }

  SPL::int64 const & get_field0() const {
    return field0_;
  }

  SPL::rstring & get_field1() {
    return field1_;
  }

  SPL::rstring const & get_field1() const {
    return field1_;
  }

  SPL::float32 & get_field2() {
    return field2_;
  }

  SPL::float32 const & get_field2() const {
    return field2_;
  }

  const MaxMinTemp$MyTuple & operator=(MaxMinTemp$MyTuple const & o) {
    if(this==&o) return *this;
    field0_ = o.field0_;
    field1_ = o.field1_;
    field2_ = o.field2_;
    return *this;
  }

  bool operator==(MaxMinTemp$MyTuple const & o) const {
    if(field0_ != o.field0_) return false;
    if(field1_ != o.field1_) return false;
    if(field2_ != o.field2_) return false;
    return true;
  }

  bool operator!=(MaxMinTemp$MyTuple const & o) const {
    return !(*this==o);
  }

  size_t hashCode() const {
    size_t r = 17;
    size_t c;
    c = std::tr1::hash<SPL::int64 >()(field0_);
    r = 37 * r + c;
    c = std::tr1::hash<SPL::rstring >()(field1_);
    r = 37 * r + c;
    c = std::tr1::hash<SPL::float32 >()(field2_);
    r = 37 * r + c;
    return r;
  }

  template <class S>
  void serialize(SPL::ByteBuffer<S> & buf) const {
    buf << field0_;
    buf << field1_;
    buf << field2_;
  }

  template <class S>
  void deserialize(SPL::ByteBuffer<S> & buf) {
    buf >> field0_;
    buf >> field1_;
    buf >> field2_;
  }

  SPL::int64 field0_;
  SPL::rstring field1_;
  SPL::float32 field2_;
};
template <class S>
inline SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const MaxMinTemp$MyTuple & v)
{
    v.serialize(buf); return buf;
}
template <class S>
inline SPL::ByteBuffer<S> & operator>>(SPL::ByteBuffer<S> & buf, MaxMinTemp$MyTuple & v)
{
    v.deserialize(buf); return buf;
}

namespace std {
  namespace tr1 {
    template <>
    struct hash<MaxMinTemp$MyTuple > {
      size_t operator()(MaxMinTemp$MyTuple const & val) const {
        return val.hashCode();
      }
    };
  }
}

namespace SPL {
  std::ostream & operator<<(std::ostream & ostr, MaxMinTemp$MyTuple const & x) {
    ostr << x.get_field0();
    ostr << x.get_field1();
    ostr << x.get_field2();
    return ostr;
  }

}

#endif /* MaxMinTemp$MyTuple_H */




#ifndef SPL_OPER_INSTANCE_MAXMINTEMP_H_
#define SPL_OPER_INSTANCE_MAXMINTEMP_H_

#include <SPL/Runtime/Common/Metric.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Window/Window.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h"
#include "../type/BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp.h"

#include <bitset>

#define MY_OPERATOR MaxMinTemp$OP
#define MY_BASE_OPERATOR MaxMinTemp_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy IPort0Type;
    typedef SPL::BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::int64 lit$0;
    SPL::int32 lit$1;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const;
    void restoreStateVariables(NetworkByteBuffer & opstate);
    void checkpointStateVariables(Checkpoint & ckpt);
    void resetStateVariables(Checkpoint & ckpt);
    void resetStateVariablesToInitialState();
    bool hasStateVariables() const;
    void resetToInitialStateRaw();
    void checkpointRaw(Checkpoint & ckpt);
    void resetRaw(Checkpoint & ckpt);

private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR, 
                    public SPL::WindowEvent<MaxMinTemp$MyTuple* >,
                    public StateHandler
{
public:
    typedef int32_t GroupByType; 
    
    typedef MaxMinTemp$MyTuple ProjectedTupleType;
    
    typedef int32_t PartitionByType; 
    typedef SPL::SlidingWindow<ProjectedTupleType* > WindowType;
    typedef SPL::WindowEvent<ProjectedTupleType* > WindowEventType;
    MY_OPERATOR();
    ~MY_OPERATOR();
    void process(Tuple const & tuple, uint32_t port); 




    void onWindowInitialFullEvent(WindowEventType::WindowType & window, 
                                  WindowEventType::PartitionType const & partition);


    void onWindowTriggerEvent(WindowEventType::WindowType & window, 
                              WindowEventType::PartitionType const & partition);

    void beforeTupleEvictionEvent(WindowEventType::WindowType & window,
                                  WindowEventType::TupleType & tuple, 
                                  WindowEventType::PartitionType const & partition);




    // StateHandler implementation
    void drain();
    void checkpoint(Checkpoint & ckpt);
    void reset(Checkpoint & ckpt);
    void resetToInitialState();

private:
    void aggregatePartition(WindowEventType::WindowType & window, 
                            WindowEventType::PartitionType const & partition);

    WindowType _window;
    Mutex    _mutex;

    std::tr1::unordered_set<WindowEventType::PartitionType> _windowFull;

    Metric& _partitionCount;
    
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_MAXMINTEMP_H_

