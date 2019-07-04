// t2t9s11stationCodeI15observationTimef4tempf7tempInFf16relativeHumidityf8dewpointk18windHeadingDegreesk14windSpeedKnotsk13windGustKnots13weatherValuess5event


#ifndef BEJWDYCEOGJAQHOFNQOLIWAMQJHRVNZ3IBTIS7LLI29TYMET_1RG96EWNERVLGA3DOTB0_0GPH2EDEMXYNMXZ_1LDNZ35HQX5TEHXWDYPD_1FOGXLINBRNBUXA2ED8XDDEAEZTVXWUQCU56AZJGUEQ_0JEOWH1I_1I20WQRGGMSFYYODVM_H_
#define BEJWDYCEOGJAQHOFNQOLIWAMQJHRVNZ3IBTIS7LLI29TYMET_1RG96EWNERVLGA3DOTB0_0GPH2EDEMXYNMXZ_1LDNZ35HQX5TEHXWDYPD_1FOGXLINBRNBUXA2ED8XDDEAEZTVXWUQCU56AZJGUEQ_0JEOWH1I_1I20WQRGGMSFYYODVM_H_

#include <SPL/Runtime/Type/Tuple.h>
#include <SPL/Runtime/Type/PrimitiveType.h>
#include <SPL/Runtime/Type/CollectionType.h>
#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Serialization/NativeByteBuffer.h>
#include <SPL/Runtime/Serialization/VirtualByteBuffer.h>
#include <SPL/Runtime/Type/Optional.h>
#include <SPL/Runtime/Utility/TimeUtils.h>

#include "BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h"


#define SELF BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm

namespace SPL {

class SELF : public Tuple
{
public:
    static const bool facade = false;

    typedef SELF Self;
    
    typedef SPL::BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy weatherValues_type;
    typedef SPL::rstring event_type;

    enum { num_attributes = 2 } ;
    
    SELF() : Tuple(), weatherValues_(), event_() {}
    SELF(const Self & ot) : Tuple(), weatherValues_(ot.weatherValues_), event_(ot.event_) 
      { constructPayload(ot); }
    SELF(const weatherValues_type & _weatherValues, const event_type & _event) : Tuple(), weatherValues_(_weatherValues), event_(_event) { }
    
    SELF(const Tuple & ot, bool typesafe = true) : Tuple() { assignFrom(ot, typesafe); }
    SELF(const ConstValueHandle & ot) : Tuple() { const Tuple & o = ot; assignFrom(o); }

    virtual ~SELF() {}
    
    weatherValues_type & get_weatherValues() { return weatherValues_; }
    const weatherValues_type & get_weatherValues() const { return weatherValues_; }
    void set_weatherValues(const weatherValues_type & _weatherValues) { weatherValues_ = _weatherValues; }
    event_type & get_event() { return event_; }
    const event_type & get_event() const { return event_; }
    void set_event(const event_type & _event) { event_ = _event; }
    virtual bool equals(const Tuple & ot) const
    {

        if (typeid(*this) != typeid(ot)) { return false; }
        const SELF & o = static_cast<const SELF &>(ot);
        return (*this == o);

    }

    virtual SELF& clear();

    Tuple* clone() const { return new Self(*this); }
    
    void serialize(VirtualByteBuffer & buf) const
    {
        buf << weatherValues_ << event_;
    }

    template <class BufferType>
    void serialize(ByteBuffer<BufferType> & buf) const
    {        
        buf << weatherValues_ << event_;
    } 
    
    void serialize(NativeByteBuffer & buf) const
    {
        this->serialize<NativeByteBuffer>(buf);
    }

    void serialize(NetworkByteBuffer & buf) const
    {
        this->serialize<NetworkByteBuffer>(buf);
    }
    
    void deserialize(VirtualByteBuffer & buf)
    {
        buf >> weatherValues_ >> event_;
    }

    template <class BufferType>
    void deserialize(ByteBuffer<BufferType> & buf)
    {        
        buf >> weatherValues_ >> event_;
    } 

    void deserialize(NativeByteBuffer & buf)
    {
        this->deserialize<NativeByteBuffer>(buf);
    }    

    void deserialize(NetworkByteBuffer & buf)
    {
        this->deserialize<NetworkByteBuffer>(buf);
    }    

    void serialize(std::ostream & ostr) const;

    void serializeWithPrecision(std::ostream & ostr) const;

    void deserialize(std::istream & istr, bool withSuffix = false);
    
    void deserializeWithNanAndInfs(std::istream & istr, bool withSuffix = false);
    
    size_t hashCode() const
    {
        size_t s = 17;
        s = 37 * s + std::tr1::hash<weatherValues_type >()(weatherValues_);
        s = 37 * s + std::tr1::hash<event_type >()(event_);
        return s;
    }
    
    size_t getSerializedSize() const
    {
        size_t size = 0;
           size += weatherValues_.getSerializedSize();
   size += event_.getSerializedSize();

        return size;

    }
    
    uint32_t getNumberOfAttributes() const 
        { return num_attributes; }

    TupleIterator getBeginIterator() 
        { return TupleIterator(*this, 0); }
    
    ConstTupleIterator getBeginIterator() const 
        { return ConstTupleIterator(*this, 0); }

    TupleIterator getEndIterator() 
        { return TupleIterator(*this, num_attributes); }

    ConstTupleIterator getEndIterator() const 
        { return ConstTupleIterator(*this, num_attributes); }
    
    TupleIterator findAttribute(const std::string & attrb)
    {
        std::tr1::unordered_map<std::string, uint32_t>::const_iterator it = mappings_->nameToIndex_.find(attrb);
        if ( it == mappings_->nameToIndex_.end() ) {
            return this->getEndIterator();
        }
        return TupleIterator(*this, it->second);
    }
    
    ConstTupleIterator findAttribute(const std::string & attrb) const
        { return const_cast<Self*>(this)->findAttribute(attrb); }
    
    TupleAttribute getAttribute(uint32_t index)
    {
        if (index >= num_attributes)
            invalidIndex (index, num_attributes);
        return TupleAttribute(mappings_->indexToName_[index], index, *this);
    }
    
    ConstTupleAttribute getAttribute(uint32_t index) const
        { return const_cast<Self*>(this)->getAttribute(index); }

    ValueHandle getAttributeValue(const std::string & attrb)
        { return getAttributeValueRaw(lookupAttributeName(*mappings_, attrb)->second); }


    ConstValueHandle getAttributeValue(const std::string & attrb) const
        { return const_cast<Self*>(this)->getAttributeValue(attrb); }

    ValueHandle getAttributeValue(uint32_t index) 
        { return getAttributeValueRaw(index); }

    ConstValueHandle getAttributeValue(uint32_t index) const
        { return const_cast<Self*>(this)->getAttributeValue(index); }

    Self & operator=(const Self & ot) 
    { 
        weatherValues_ = ot.weatherValues_;
        event_ = ot.event_; 
        assignPayload(ot);
        return *this; 
    }

    Self & operator=(const Tuple & ot) 
    { 
        assignFrom(ot); 
        return *this; 
    }

    void assign(Tuple const & tuple)
    {
        *this = static_cast<SELF const &>(tuple);
    }


    bool operator==(const Self & ot) const 
    {  
       return ( 
                weatherValues_ == ot.weatherValues_ && 
                event_ == ot.event_  
              ); 
    }
    bool operator==(const Tuple & ot) const { return equals(ot); }

    bool operator!=(const Self & ot) const { return !(*this == ot); }
    bool operator!=(const Tuple & ot) const { return !(*this == ot); }


    void swap(SELF & ot) 
    { 
        std::swap(weatherValues_, ot.weatherValues_);
        std::swap(event_, ot.event_);
      std::swap(payload_, ot.payload_);
    }

    void reset()
    { 
        *this = SELF(); 
    }

    void normalizeBoundedSetsAndMaps(); 

    const std::string & getAttributeName(uint32_t index) const
    {
        if (index >= num_attributes)
            invalidIndex (index, num_attributes);
        return mappings_->indexToName_[index];
    }

    const std::tr1::unordered_map<std::string, uint32_t> & getAttributeNames() const 
        { return mappings_->nameToIndex_; }


protected:

    ValueHandle getAttributeValueRaw(const uint32_t index)
    {
        if (index >= num_attributes)
            invalidIndex(index, num_attributes);
        const TypeOffset & t = mappings_->indexToTypeOffset_[index];
        return ValueHandle((char*)this + t.getOffset(), t.getMetaType(), &t.getTypeId());
    }

private:
    
    weatherValues_type weatherValues_;
    event_type event_;

    static TupleMappings* mappings_;
    static TupleMappings* initMappings();
};

inline VirtualByteBuffer & operator>>(VirtualByteBuffer & sbuf, SELF & tuple) 
    { tuple.deserialize(sbuf); return sbuf; }
inline VirtualByteBuffer & operator<<(VirtualByteBuffer & sbuf, SELF const & tuple) 
    { tuple.serialize(sbuf); return sbuf; }

template <class BufferType>
inline ByteBuffer<BufferType> & operator>>(ByteBuffer<BufferType> & sbuf, SELF & tuple) 
    { tuple.deserialize(sbuf); return sbuf; }
template <class BufferType>
inline ByteBuffer<BufferType> & operator<<(ByteBuffer<BufferType> & sbuf, SELF const & tuple) 
    { tuple.serialize(sbuf); return sbuf; }

inline NetworkByteBuffer & operator>>(NetworkByteBuffer & sbuf, SELF & tuple) 
    { tuple.deserialize(sbuf); return sbuf; }
inline NetworkByteBuffer & operator<<(NetworkByteBuffer & sbuf, SELF const & tuple) 
    { tuple.serialize(sbuf); return sbuf; }

inline NativeByteBuffer & operator>>(NativeByteBuffer & sbuf, SELF & tuple) 
    { tuple.deserialize(sbuf); return sbuf; }
inline NativeByteBuffer & operator<<(NativeByteBuffer & sbuf, SELF const & tuple) 
    { tuple.serialize(sbuf); return sbuf; }

template<>
inline std::ostream & serializeWithPrecision(std::ostream & ostr, SELF const & tuple) 
    { tuple.serializeWithPrecision(ostr); return ostr; }
inline std::ostream & operator<<(std::ostream & ostr, SELF const & tuple) 
    { tuple.serialize(ostr); return ostr; }
inline std::istream & operator>>(std::istream & istr, SELF & tuple) 
    { tuple.deserialize(istr); return istr; }
template<>
inline void deserializeWithSuffix(std::istream & istr, SELF  & tuple) 
{ tuple.deserialize(istr,true);  }
inline void deserializeWithNanAndInfs(std::istream & istr, SELF  & tuple, bool withSuffix = false) 
{ tuple.deserializeWithNanAndInfs(istr,withSuffix);  }



}  // namespace SPL

namespace std
{
    inline void swap(SPL::SELF & a, SPL::SELF & b)
    {
        a.swap(b);
    }
}

namespace std { 
    namespace tr1 {
        template <>
        struct hash<SPL::SELF> {
            inline size_t operator()(const SPL::SELF & self) const 
                { return self.hashCode(); }
        };
    }
}

#undef SELF
#endif // BEJWDYCEOGJAQHOFNQOLIWAMQJHRVNZ3IBTIS7LLI29TYMET_1RG96EWNERVLGA3DOTB0_0GPH2EDEMXYNMXZ_1LDNZ35HQX5TEHXWDYPD_1FOGXLINBRNBUXA2ED8XDDEAEZTVXWUQCU56AZJGUEQ_0JEOWH1I_1I20WQRGGMSFYYODVM_H_ 


