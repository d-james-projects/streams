// eJzNk1tzokAQhav_1SmofkhcBb5X4JtFodL2Ul1jrCzU6rc4KDDvTSPTX74jRyJqseUzBC01_1Z5rTBx35uZiEL2hbqdSwFke_0mDNCcMA2lwM3uZxlbtpGaLnYSvi2Xu8t19WOy6u77qQ93wwH8vdj_1JC0XM8eVrudVj4_1KCdaF4qb9cAtlgYd4o2xZ5dZ7NlJYecvJqOqvWTjnpg9vfiD51GBKXcxmtxPp2V_159m_1RtHYbvdL7nRLK9Ft1Polveq7i9VLt8_0KzW6Dmn8WnuM_1PG9qk9zqJp3TfMEPG4b9n5XKwpeMykUAsFYyQEuTQhZoxgMRWolUax2xOVq44Ug4J4szYhDKEG3IA4kAezEZxYzW8YAqkRKzmPBJIcIatwZJG5U5RYRLM4uIpDKtuSWSp4mRkOGj5Hh7B_1XXSKHWpnBgRLiXzhJyplFtUmpkRslSznvzQeE7bgQEqDQ8APdwZgAcLfrnE_0FgA2EQQWp3IQ8ck0ia_0qmQWhAr7AjfFzOm9J5yypCIkDeRcaNbw6XZyfmLYYTI26Gk82Ij1nRe23sqv72ngfH0YzedY1S_1ksCPrT9JfC2QmU05mT_1FFLL0vtcgF_1u8gh37DfrZ5s_0HNo9Z_1gIyQp9G5b9Kl9Sb1EW4rsq8E28Sl1G8onACbu9MbP8CK27aCj

#ifndef WeatherSummary$NoDuplicates$KeyType_H
#define WeatherSummary$NoDuplicates$KeyType_H
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Serialization/ByteBuffer.h>
#include <SPL/Runtime/Utility/TimeUtils.h>
#include "../../type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.h"

class WeatherSummary$NoDuplicates$KeyType {
public:
  WeatherSummary$NoDuplicates$KeyType() {}


  WeatherSummary$NoDuplicates$KeyType(const WeatherSummary$NoDuplicates$KeyType & o) :
    field0_(o.field0_),
    field1_(o.field1_)
  {}

  WeatherSummary$NoDuplicates$KeyType(
    const SPL::rstring & field0,
    const SPL::int64 & field1
  ) :
    field0_(field0),
    field1_(field1)
  {}

  SPL::rstring & get_field0() {
    return field0_;
  }

  SPL::rstring const & get_field0() const {
    return field0_;
  }

  SPL::int64 & get_field1() {
    return field1_;
  }

  SPL::int64 const & get_field1() const {
    return field1_;
  }

  const WeatherSummary$NoDuplicates$KeyType & operator=(WeatherSummary$NoDuplicates$KeyType const & o) {
    if(this==&o) return *this;
    field0_ = o.field0_;
    field1_ = o.field1_;
    return *this;
  }

  bool operator==(WeatherSummary$NoDuplicates$KeyType const & o) const {
    if(field0_ != o.field0_) return false;
    if(field1_ != o.field1_) return false;
    return true;
  }

  bool operator!=(WeatherSummary$NoDuplicates$KeyType const & o) const {
    return !(*this==o);
  }

  size_t hashCode() const {
    size_t r = 17;
    size_t c;
    c = std::tr1::hash<SPL::rstring >()(field0_);
    r = 37 * r + c;
    c = std::tr1::hash<SPL::int64 >()(field1_);
    r = 37 * r + c;
    return r;
  }

  template <class S>
  void serialize(SPL::ByteBuffer<S> & buf) const {
    buf << field0_;
    buf << field1_;
  }

  template <class S>
  void deserialize(SPL::ByteBuffer<S> & buf) {
    buf >> field0_;
    buf >> field1_;
  }

  SPL::rstring field0_;
  SPL::int64 field1_;
};
template <class S>
inline SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const WeatherSummary$NoDuplicates$KeyType & v)
{
    v.serialize(buf); return buf;
}
template <class S>
inline SPL::ByteBuffer<S> & operator>>(SPL::ByteBuffer<S> & buf, WeatherSummary$NoDuplicates$KeyType & v)
{
    v.deserialize(buf); return buf;
}

namespace std {
  namespace tr1 {
    template <>
    struct hash<WeatherSummary$NoDuplicates$KeyType > {
      size_t operator()(WeatherSummary$NoDuplicates$KeyType const & val) const {
        return val.hashCode();
      }
    };
  }
}

namespace SPL {
  std::ostream & operator<<(std::ostream & ostr, WeatherSummary$NoDuplicates$KeyType const & x) {
    ostr << x.get_field0();
    ostr << x.get_field1();
    return ostr;
  }

}

#endif /* WeatherSummary$NoDuplicates$KeyType_H */


#ifndef SPL_OPER_INSTANCE_WEATHERSUMMARY_NODUPLICATES_H_
#define SPL_OPER_INSTANCE_WEATHERSUMMARY_NODUPLICATES_H_

#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../../type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.h"

#include <bitset>

#define MY_OPERATOR NoDuplicates$OP
#define MY_BASE_OPERATOR NoDuplicates_Base
#define MY_OPERATOR_SCOPE SPL::_Operator::WeatherSummary

namespace SPL {
namespace _Operator {
namespace WeatherSummary {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW IPort0Type;
    typedef SPL::BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW OPort0Type;
    
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
    
    
    
    SPL::float64 lit$0;
    
    
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
    public StateHandler
{
public:
    MY_OPERATOR();

    virtual void process(Punctuation const & punct, uint32_t port);
    virtual void process(Tuple const & tuple, uint32_t port);

    virtual void checkpoint(Checkpoint & ckpt);
    virtual void reset(Checkpoint & ckpt);
    virtual void resetToInitialState();

    typedef WeatherSummary$NoDuplicates$KeyType KeyType;
    struct ListDataType {
        ListDataType(KeyType const & k, double value)
            : _key(k), _value(value) {}

        ListDataType() {}
 
        void checkpoint(Checkpoint & ckpt) {
            ckpt << _key;
            ckpt << _value;
        }

        void reset(Checkpoint & ckpt) {
            ckpt >> _key;
            ckpt >> _value;
        }

        KeyType _key;
        double _value;
    };
    typedef std::list<ListDataType> TupleListType;
    typedef TupleListType::iterator ListElementIter;
    typedef std::tr1::unordered_map<KeyType, ListElementIter> TupleMapType;

private:
    void resetCommon();

    Mutex                  _mutex;
    
        double             _diff;        // time for 'uniqueness'
    
    TupleMapType           _map;         // The tuples to be checked
    TupleListType          _list;        // The ordered list of tuples

}; 

} // namespace WeatherSummary
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_WEATHERSUMMARY_NODUPLICATES_H_

