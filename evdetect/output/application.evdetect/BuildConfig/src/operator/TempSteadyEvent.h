// eJzVVNtyokoUrf4TypqawqoMgk68UDNThYrRiBKVqMkL1cIONCMXoRHI10_1rqCHJ5OHUOQ9z8AH3hV6711rdVugLZOMLCY0B_04lgQSTLE0wtdw4O5EhCIvs1UEUQarSIoNaF28wulqru_1FQmrq4_0T7FGEvHBvUvDweRW3PZXzVZ9Ic42hSlpRWGY0rTxNZpP7oeDjh5P1mGzvrMcrZW2bxcj0Yu8Xrpq7jtiL_1B0U6prqeePe8_0m2Cskz1hsdmprFY_0H1sNquGg_1WLniYxKZohoqd51l2xH1QS7l7dZze7rzxoXgVt6OarFRPWXm6oNgF2pkhSczz43308cG6VKyaG01Uu_1Qwgc26dzpNNXVVI2XmoMb_1dDoiqboRG4dbHWyLgI_1f2SbsoPnxrU7y68NcNcru4j6pvSk3_0TaaLqZT7tpjuuq3V73_06qiPhrLdZbOeul1U3n0nHvYmaIH_0mooEVMidTHbzW8cP3kqCr2_199_0NH0_1us2JcXN8a90XUVRQjy_05Gh66DKqjmhj7UTtJh2ydBLQvjn0mELajB3gYKFq3ZmGIUhAEcdIwwpRAHTNfFnSbLMfuYBA5brBzyFYFLKGC7_0JevShX1wiChOKAMOaaEkjDoFu_1RSRTG9JMoOEBN1n5o64U28FWk5lEMScISiP2xiYUpJOcFPqTovKEPG3iel_0VjyyANrANecvS9K8t4k_1B8eSAKfjQKBnyV_08KVD4csazihf25lD_1ftO3dEeNqGmDbqvCSITyz9_0TP3X2APSPxPwBtH8OorQqUX5l_1o_0nsPNyIo_1m181EEll6Czj8JNAvH_0mDeID4gEtPkVHWhBJxrQiaNLHMOW9e9hmPrEJrS4FGzIopAtcElkJLCHzNQMqA9ODMyFrCw1j4VFBGCPg5CWkzdpQsu5A93he7r_1TxcU8pkEjAtgboV4ibcpo4Gm0Ra_0nUTgSsJcHQXg3shydWKUO2jxKmDCXOK3wlwKZ2GujqRy72UpFV5kKSUvsvxAkpKMXl0mf7H5X44q7IH58mz6V3v46D5f_1L6VDUZypcp8_0AtVUqQ7

#ifndef TempSteadyEvent$PartitionByType_H
#define TempSteadyEvent$PartitionByType_H
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Serialization/ByteBuffer.h>
#include <SPL/Runtime/Utility/TimeUtils.h>
#include "../type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h"
#include "../type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.h"
#include "../type/BeJwrMUwyKy5JTUypBAATwwPI.h"

class TempSteadyEvent$PartitionByType {
public:
  TempSteadyEvent$PartitionByType() {}


  TempSteadyEvent$PartitionByType(const TempSteadyEvent$PartitionByType & o) :
    field0_(o.field0_)
  {}

  TempSteadyEvent$PartitionByType(
    const SPL::rstring & field0
  ) :
    field0_(field0)
  {}

  SPL::rstring & get_field0() {
    return field0_;
  }

  SPL::rstring const & get_field0() const {
    return field0_;
  }

  const TempSteadyEvent$PartitionByType & operator=(TempSteadyEvent$PartitionByType const & o) {
    if(this==&o) return *this;
    field0_ = o.field0_;
    return *this;
  }

  bool operator==(TempSteadyEvent$PartitionByType const & o) const {
    if(field0_ != o.field0_) return false;
    return true;
  }

  bool operator!=(TempSteadyEvent$PartitionByType const & o) const {
    return !(*this==o);
  }

  size_t hashCode() const {
    size_t r = 17;
    size_t c;
    c = std::tr1::hash<SPL::rstring >()(field0_);
    r = 37 * r + c;
    return r;
  }

  template <class S>
  void serialize(SPL::ByteBuffer<S> & buf) const {
    buf << field0_;
  }

  template <class S>
  void deserialize(SPL::ByteBuffer<S> & buf) {
    buf >> field0_;
  }

  SPL::rstring field0_;
};
template <class S>
inline SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const TempSteadyEvent$PartitionByType & v)
{
    v.serialize(buf); return buf;
}
template <class S>
inline SPL::ByteBuffer<S> & operator>>(SPL::ByteBuffer<S> & buf, TempSteadyEvent$PartitionByType & v)
{
    v.deserialize(buf); return buf;
}

namespace std {
  namespace tr1 {
    template <>
    struct hash<TempSteadyEvent$PartitionByType > {
      size_t operator()(TempSteadyEvent$PartitionByType const & val) const {
        return val.hashCode();
      }
    };
  }
}

namespace SPL {
  std::ostream & operator<<(std::ostream & ostr, TempSteadyEvent$PartitionByType const & x) {
    ostr << x.get_field0();
    return ostr;
  }

}

#endif /* TempSteadyEvent$PartitionByType_H */


#include <string>
struct PartialMatches;

#ifndef SPL_OPER_INSTANCE_TEMPSTEADYEVENT_H_
#define SPL_OPER_INSTANCE_TEMPSTEADYEVENT_H_

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

#include "../type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h"
#include "../type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.h"
#include "../type/BeJwrMUwyKy5JTUypBAATwwPI.h"

#include <bitset>

#define MY_OPERATOR TempSteadyEvent$OP
#define MY_BASE_OPERATOR TempSteadyEvent_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy IPort0Type;
    typedef SPL::BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm OPort0Type;
    
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
    
    
    
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
    SPL::rstring param$pattern$0;
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


class MY_OPERATOR : public MY_BASE_OPERATOR 

{
public:
  typedef TempSteadyEvent$PartitionByType PartitionByType;
  MY_OPERATOR();
  virtual ~MY_OPERATOR(); 
  void process(Tuple const & tuple, uint32_t port);
  
  
private:
  
     typedef std::tr1::unordered_map<TempSteadyEvent$PartitionByType, PartialMatches*> PartitionType;
     PartitionType _partitions;
  
  
  PartialMatches *_partialMatches;
  Mutex _mutex;
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_TEMPSTEADYEVENT_H_


