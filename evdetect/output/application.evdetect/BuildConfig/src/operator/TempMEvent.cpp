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


#include "./TempMEvent.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR TempMEvent_Base
#define MY_OPERATOR TempMEvent$OP






// Partial Match Structure
struct PartialMatch {
    int32_t _state;
    int32_t _Count;

       struct Aggregates {
	    struct { SPL::float32 _Last;SPL::float32 _First;} tempInF;

        };
        Aggregates _attrs;
    
    PartialMatch() {
    _state = 0;
    _Count = 0;
    }
    PartialMatch(int32_t state, MY_OPERATOR_SCOPE::MY_OPERATOR::IPort0Type const & iport$0)
        : _state(state), _Count(1)
    {

                    _attrs.tempInF._Last = iport$0.get_tempInF();
                
                    _attrs.tempInF._First = iport$0.get_tempInF();
                
    }
    PartialMatch(int32_t state, MY_OPERATOR_SCOPE::MY_OPERATOR::IPort0Type const & iport$0, PartialMatch const & rhs)
        : _state(state), _Count(1 + rhs._Count)
    {

                    _attrs.tempInF._Last = iport$0.get_tempInF();
                
                    _attrs.tempInF._First = rhs._attrs.tempInF._First;
                
    }
};

struct PartialMatches {
    std::vector<PartialMatch*> _pms;
    void deleteAll() {
        for (int i=0, n=_pms.size(); i<n; i++)
          delete _pms.at(i);
        _pms.clear();
    }
    
};

MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
{
    
    
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR() 
{
    
        for (PartitionType::const_iterator it = _partitions.begin(); it != _partitions.end(); it++) {
            it->second->deleteAll();
            delete it->second;
        }
    
}

#define MATCH$COUNT 1
#define MATCH$MATCH false

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
    IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);
    AutoPortMutex apm(_mutex, *this);
    
        PartitionByType key(iport$0.get_stationCode());
        PartitionType::iterator it = _partitions.find(key);
        if (it == _partitions.end())
            it = _partitions.insert (std::make_pair (key, new PartialMatches)).first;
        PartialMatches & partialMatches = *it->second;
    
    std::vector<PartialMatch*> oldPms(partialMatches._pms);
    partialMatches._pms.clear();
    int longestAccepting = -1;
    /*create new partial matches */
        if (true) { /* predicate: . */
	   PartialMatch * newPm = new PartialMatch(1, iport$0);
	   partialMatches._pms.push_back(newPm);
	}


    /*update existing partial matches*/
    for (int i=0, n=oldPms.size(); i<n; i++) {
        PartialMatch & pmatch = *oldPms.at(i);
        switch (pmatch._state) {
    
           case 0: { /* state 0 */
               if (true) { /* predicate: . */
		   PartialMatch * newPm = new PartialMatch(1, iport$0, pmatch);
		   partialMatches._pms.push_back(newPm);
		}

               break;
           }
        
           case 1: { /* state 1 */
               if (((iport$0.get_tempInF() > pmatch._attrs.tempInF._First) && (iport$0.get_tempInF() >= pmatch._attrs.tempInF._Last))) { /* predicate: rise */
		   PartialMatch * newPm = new PartialMatch(2, iport$0, pmatch);
		   partialMatches._pms.push_back(newPm);
		}

               break;
           }
        
           case 2: { /* state 2 */
               if (((iport$0.get_tempInF() > pmatch._attrs.tempInF._First) && (iport$0.get_tempInF() >= pmatch._attrs.tempInF._Last))) { /* predicate: rise */
		   PartialMatch * newPm = new PartialMatch(2, iport$0, pmatch);
		   partialMatches._pms.push_back(newPm);
		}
    if (((iport$0.get_tempInF() >= pmatch._attrs.tempInF._First) && (iport$0.get_tempInF() < pmatch._attrs.tempInF._Last))) { /* predicate: drop */
		   PartialMatch * newPm = new PartialMatch(3, iport$0, pmatch);
		   partialMatches._pms.push_back(newPm);
		}

               break;
           }
        
           case 3: { /* state 3 */
               if (((iport$0.get_tempInF() >= pmatch._attrs.tempInF._First) && (iport$0.get_tempInF() < pmatch._attrs.tempInF._Last))) { /* predicate: drop */
		   PartialMatch * newPm = new PartialMatch(3, iport$0, pmatch);
		   partialMatches._pms.push_back(newPm);
		}
    if (((iport$0.get_tempInF() > pmatch._attrs.tempInF._First) && (iport$0.get_tempInF() >= pmatch._attrs.tempInF._Last))) { /* predicate: rise */
		   PartialMatch * newPm = new PartialMatch(4, iport$0, pmatch);
		   partialMatches._pms.push_back(newPm);
		}

               break;
           }
        
           case 4: { /* state 4 */
               if (((iport$0.get_tempInF() > pmatch._attrs.tempInF._First) && (iport$0.get_tempInF() >= pmatch._attrs.tempInF._Last))) { /* predicate: rise */
		   PartialMatch * newPm = new PartialMatch(4, iport$0, pmatch);
		   partialMatches._pms.push_back(newPm);
		}
    if (((iport$0.get_tempInF() >= pmatch._attrs.tempInF._First) && (iport$0.get_tempInF() < pmatch._attrs.tempInF._Last))) { /* predicate: drop */
		   PartialMatch * newPm = new PartialMatch(5, iport$0, pmatch);
		   partialMatches._pms.push_back(newPm);
		}
    if (((iport$0.get_tempInF() < pmatch._attrs.tempInF._First) && (iport$0.get_tempInF() < pmatch._attrs.tempInF._Last))) { /* predicate: deep */
		   PartialMatch * newPm = new PartialMatch(6, iport$0, pmatch);
		   partialMatches._pms.push_back(newPm);
		    int currAccepting = partialMatches._pms.size() - 1;
		    if (-1 == longestAccepting || partialMatches._pms.at(currAccepting)->_Count > partialMatches._pms.at(longestAccepting)->_Count)
			longestAccepting = currAccepting;
		}

               break;
           }
        
           case 5: { /* state 5 */
               if (((iport$0.get_tempInF() >= pmatch._attrs.tempInF._First) && (iport$0.get_tempInF() < pmatch._attrs.tempInF._Last))) { /* predicate: drop */
		   PartialMatch * newPm = new PartialMatch(5, iport$0, pmatch);
		   partialMatches._pms.push_back(newPm);
		}
    if (((iport$0.get_tempInF() < pmatch._attrs.tempInF._First) && (iport$0.get_tempInF() < pmatch._attrs.tempInF._Last))) { /* predicate: deep */
		   PartialMatch * newPm = new PartialMatch(6, iport$0, pmatch);
		   partialMatches._pms.push_back(newPm);
		    int currAccepting = partialMatches._pms.size() - 1;
		    if (-1 == longestAccepting || partialMatches._pms.at(currAccepting)->_Count > partialMatches._pms.at(longestAccepting)->_Count)
			longestAccepting = currAccepting;
		}

               break;
           }
        
           case 6: { /* state 6 */
           
               break;
           }
        
        }
        delete &pmatch;
    }

    /*submit longest accepting match*/
    if (-1 != longestAccepting) {
#undef MATCH$COUNT
#define MATCH$COUNT 0
#undef MATCH$MATCH
#define MATCH$MATCH SPL::boolean(true)
        PartialMatch & pmatch = *partialMatches._pms.at(longestAccepting);
        
        OPort0Type otuple(iport$0, SPL::rstring("M-Shape Temp"));
        submit(otuple, 0);
        submit(Punctuation::WindowMarker, 0);
        partialMatches.deleteAll();
    }

}



static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("TempMEvent",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator()  {
    uint32_t index = getIndex();
    param$pattern$0 = SPL::rstring(". rise+ drop+ rise+ drop* deep");
    addParameterValue ("pattern", SPL::ConstValueHandle(param$pattern$0));
    addParameterValue ("partitionBy");
    addParameterValue ("predicates");
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



