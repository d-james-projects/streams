// eJzVVW1vokoUzvwTYjYb3e1V0Na37G7iC9ZWkCpWbb_0QEU5hqDA4DAr99Tv2VkvtbbK5ubnZDV9mzjk8PPM85ww2DcpkFZRjzgAHcdmGqN3WMbe9KbiQIgXJ4qmhQrlc4VkElS5c75xsrhruY0f3DPVpjDUSy3feTUIH_0rW87i_1qjaopT1aZpWhZNrOUce08muq3w0HLYPqS1qsb29UaSfPavJL9yO8li_1q2JfdC37CUqpb4waj3ZMm9TPFn5mqjNhZsNLTvFkOzeWennQCTyJJV2rlpzZuubAxSJW02nprjjT_1Kyl7hlKotqPqdiWcMwg3VyALrE99j2_1F9jXQ5MRtrjVRbPAtAMJ26rbq6GKtsrrm41qezrmzJbuRVwVH1ZRYG6b04lBM_01S68SXoxA2_05cLKobykPxmWqXY1X03E3SXFVdZrLfl_1tqPez_0XKXTHrJRb1z77u3sLFkH4zFUCGWQqrybjO9dIP4IcuM_1jZ4R5_1pt_0fZyKbx7FHOTDMcabueucGPg46aXXac3f6FvUGo4tEAKi8uYicgYWVH2WMcYRsqsHWAg80rDuYYhTSEvaUR5hxYKCw2b7R2m4mXSegKsPy2WChLjMTwVXIYjb7m1l8kByAqlFCPhjHHIReAjBNOaNjN3oOSiDL_0SS67wC1Rvi_1rUQeKJaSmEYM4FgEkFg6xMYf4APArIhwo_10ptsVjMM_0EQRFfhoFiSfkj5vm_03B0Rw_1_0faUkn6_1Fn6COf7CZCGP8YpnUkf8jnF_0beEvv03fE5h_1hc6b5pDee2iV79_136sIEcT_0nk3UQrmOR4eZoKsY2PY5PiMBIBLy_0jnaHx89rCnmtSp60eK4Z7AW9VsYJgFxCM_0OCQd2ERUAx8COhM4QsCM_01AeXgZgokVbqzwkzAnBGIeX54GUS83xsLzd9L_1efdJ2iQFggtADMPWBzvE6EDDyJ1vDtxQQpZ8zZswHSiS1nL4pKey_1ebIQxx_12pMcfEwZizZ1Gl97bkEq_025IJHW34gpRNfvbkYf_0Pmfx1V2ILoy0PTvznDR78c_1S_1TwxFIM6FyoSQa8SfZeNvz

#ifndef TempMEvent$PartitionByType_H
#define TempMEvent$PartitionByType_H
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Serialization/ByteBuffer.h>
#include <SPL/Runtime/Utility/TimeUtils.h>
#include "../type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h"
#include "../type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.h"
#include "../type/BeJwrMU4yKcosTk0ySSnKLwCSqakFAEyGAdw.h"

class TempMEvent$PartitionByType {
public:
  TempMEvent$PartitionByType() {}


  TempMEvent$PartitionByType(const TempMEvent$PartitionByType & o) :
    field0_(o.field0_)
  {}

  TempMEvent$PartitionByType(
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

  const TempMEvent$PartitionByType & operator=(TempMEvent$PartitionByType const & o) {
    if(this==&o) return *this;
    field0_ = o.field0_;
    return *this;
  }

  bool operator==(TempMEvent$PartitionByType const & o) const {
    if(field0_ != o.field0_) return false;
    return true;
  }

  bool operator!=(TempMEvent$PartitionByType const & o) const {
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
inline SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const TempMEvent$PartitionByType & v)
{
    v.serialize(buf); return buf;
}
template <class S>
inline SPL::ByteBuffer<S> & operator>>(SPL::ByteBuffer<S> & buf, TempMEvent$PartitionByType & v)
{
    v.deserialize(buf); return buf;
}

namespace std {
  namespace tr1 {
    template <>
    struct hash<TempMEvent$PartitionByType > {
      size_t operator()(TempMEvent$PartitionByType const & val) const {
        return val.hashCode();
      }
    };
  }
}

namespace SPL {
  std::ostream & operator<<(std::ostream & ostr, TempMEvent$PartitionByType const & x) {
    ostr << x.get_field0();
    return ostr;
  }

}

#endif /* TempMEvent$PartitionByType_H */


#include <string>
struct PartialMatches;

#ifndef SPL_OPER_INSTANCE_TEMPMEVENT_H_
#define SPL_OPER_INSTANCE_TEMPMEVENT_H_

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
#include "../type/BeJwrMU4yKcosTk0ySSnKLwCSqakFAEyGAdw.h"

#include <bitset>

#define MY_OPERATOR TempMEvent$OP
#define MY_BASE_OPERATOR TempMEvent_Base
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
  typedef TempMEvent$PartitionByType PartitionByType;
  MY_OPERATOR();
  virtual ~MY_OPERATOR(); 
  void process(Tuple const & tuple, uint32_t port);
  
  
private:
  
     typedef std::tr1::unordered_map<TempMEvent$PartitionByType, PartialMatches*> PartitionType;
     PartitionType _partitions;
  
  
  PartialMatches *_partialMatches;
  Mutex _mutex;
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_TEMPMEVENT_H_


