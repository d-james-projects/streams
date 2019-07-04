// t6f7maxTemps14maxTempStationI18maxObservationTimef7minTemps14minTempStationI18minObservationTime


#ifndef BEJWRMUSZZ02SCENNLSG2NIGYGKSSSZLZ8ZWNLYAC_1KNFQUVLYIGQZNXUOPLMPJHYCATJEWYEMNIA6RYKDP_H_
#define BEJWRMUSZZ02SCENNLSG2NIGYGKSSSZLZ8ZWNLYAC_1KNFQUVLYIGQZNXUOPLMPJHYCATJEWYEMNIA6RYKDP_H_

#include <SPL/Runtime/Type/Tuple.h>
#include <SPL/Runtime/Type/PrimitiveType.h>
#include <SPL/Runtime/Type/CollectionType.h>
#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Serialization/NativeByteBuffer.h>
#include <SPL/Runtime/Serialization/VirtualByteBuffer.h>
#include <SPL/Runtime/Type/Optional.h>
#include <SPL/Runtime/Utility/TimeUtils.h>



#define SELF BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp

namespace SPL {

class SELF : public Tuple
{
public:
    static const bool facade = false;

    typedef SELF Self;
    
    typedef SPL::float32 maxTemp_type;
    typedef SPL::rstring maxTempStation_type;
    typedef SPL::int64 maxObservationTime_type;
    typedef SPL::float32 minTemp_type;
    typedef SPL::rstring minTempStation_type;
    typedef SPL::int64 minObservationTime_type;

    enum { num_attributes = 6 } ;
    
    SELF() : Tuple(), maxTemp_(), maxTempStation_(), maxObservationTime_(), minTemp_(), minTempStation_(), minObservationTime_() {}
    SELF(const Self & ot) : Tuple(), maxTemp_(ot.maxTemp_), maxTempStation_(ot.maxTempStation_), maxObservationTime_(ot.maxObservationTime_), minTemp_(ot.minTemp_), minTempStation_(ot.minTempStation_), minObservationTime_(ot.minObservationTime_) 
      { constructPayload(ot); }
    SELF(const maxTemp_type & _maxTemp, const maxTempStation_type & _maxTempStation, const maxObservationTime_type & _maxObservationTime, const minTemp_type & _minTemp, const minTempStation_type & _minTempStation, const minObservationTime_type & _minObservationTime) : Tuple(), maxTemp_(_maxTemp), maxTempStation_(_maxTempStation), maxObservationTime_(_maxObservationTime), minTemp_(_minTemp), minTempStation_(_minTempStation), minObservationTime_(_minObservationTime) { }
    
    SELF(const Tuple & ot, bool typesafe = true) : Tuple() { assignFrom(ot, typesafe); }
    SELF(const ConstValueHandle & ot) : Tuple() { const Tuple & o = ot; assignFrom(o); }

    virtual ~SELF() {}
    
    maxTemp_type & get_maxTemp() { return maxTemp_; }
    const maxTemp_type & get_maxTemp() const { return maxTemp_; }
    void set_maxTemp(const maxTemp_type & _maxTemp) { maxTemp_ = _maxTemp; }
    maxTempStation_type & get_maxTempStation() { return maxTempStation_; }
    const maxTempStation_type & get_maxTempStation() const { return maxTempStation_; }
    void set_maxTempStation(const maxTempStation_type & _maxTempStation) { maxTempStation_ = _maxTempStation; }
    maxObservationTime_type & get_maxObservationTime() { return maxObservationTime_; }
    const maxObservationTime_type & get_maxObservationTime() const { return maxObservationTime_; }
    void set_maxObservationTime(const maxObservationTime_type & _maxObservationTime) { maxObservationTime_ = _maxObservationTime; }
    minTemp_type & get_minTemp() { return minTemp_; }
    const minTemp_type & get_minTemp() const { return minTemp_; }
    void set_minTemp(const minTemp_type & _minTemp) { minTemp_ = _minTemp; }
    minTempStation_type & get_minTempStation() { return minTempStation_; }
    const minTempStation_type & get_minTempStation() const { return minTempStation_; }
    void set_minTempStation(const minTempStation_type & _minTempStation) { minTempStation_ = _minTempStation; }
    minObservationTime_type & get_minObservationTime() { return minObservationTime_; }
    const minObservationTime_type & get_minObservationTime() const { return minObservationTime_; }
    void set_minObservationTime(const minObservationTime_type & _minObservationTime) { minObservationTime_ = _minObservationTime; }
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
        buf << maxTemp_ << maxTempStation_ << maxObservationTime_ << minTemp_ << minTempStation_ << minObservationTime_;
    }

    template <class BufferType>
    void serialize(ByteBuffer<BufferType> & buf) const
    {        
        buf << maxTemp_ << maxTempStation_ << maxObservationTime_ << minTemp_ << minTempStation_ << minObservationTime_;
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
        buf >> maxTemp_ >> maxTempStation_ >> maxObservationTime_ >> minTemp_ >> minTempStation_ >> minObservationTime_;
    }

    template <class BufferType>
    void deserialize(ByteBuffer<BufferType> & buf)
    {        
        buf >> maxTemp_ >> maxTempStation_ >> maxObservationTime_ >> minTemp_ >> minTempStation_ >> minObservationTime_;
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
        s = 37 * s + std::tr1::hash<maxTemp_type >()(maxTemp_);
        s = 37 * s + std::tr1::hash<maxTempStation_type >()(maxTempStation_);
        s = 37 * s + std::tr1::hash<maxObservationTime_type >()(maxObservationTime_);
        s = 37 * s + std::tr1::hash<minTemp_type >()(minTemp_);
        s = 37 * s + std::tr1::hash<minTempStation_type >()(minTempStation_);
        s = 37 * s + std::tr1::hash<minObservationTime_type >()(minObservationTime_);
        return s;
    }
    
    size_t getSerializedSize() const
    {
        size_t size = sizeof(SPL::float32)+sizeof(SPL::int64)+sizeof(SPL::float32)+sizeof(SPL::int64);
           size += maxTempStation_.getSerializedSize();
   size += minTempStation_.getSerializedSize();

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
        maxTemp_ = ot.maxTemp_;
        maxTempStation_ = ot.maxTempStation_;
        maxObservationTime_ = ot.maxObservationTime_;
        minTemp_ = ot.minTemp_;
        minTempStation_ = ot.minTempStation_;
        minObservationTime_ = ot.minObservationTime_; 
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
                maxTemp_ == ot.maxTemp_ && 
                maxTempStation_ == ot.maxTempStation_ && 
                maxObservationTime_ == ot.maxObservationTime_ && 
                minTemp_ == ot.minTemp_ && 
                minTempStation_ == ot.minTempStation_ && 
                minObservationTime_ == ot.minObservationTime_  
              ); 
    }
    bool operator==(const Tuple & ot) const { return equals(ot); }

    bool operator!=(const Self & ot) const { return !(*this == ot); }
    bool operator!=(const Tuple & ot) const { return !(*this == ot); }


    void swap(SELF & ot) 
    { 
        std::swap(maxTemp_, ot.maxTemp_);
        std::swap(maxTempStation_, ot.maxTempStation_);
        std::swap(maxObservationTime_, ot.maxObservationTime_);
        std::swap(minTemp_, ot.minTemp_);
        std::swap(minTempStation_, ot.minTempStation_);
        std::swap(minObservationTime_, ot.minObservationTime_);
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
    
    maxTemp_type maxTemp_;
    maxTempStation_type maxTempStation_;
    maxObservationTime_type maxObservationTime_;
    minTemp_type minTemp_;
    minTempStation_type minTempStation_;
    minObservationTime_type minObservationTime_;

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
#endif // BEJWRMUSZZ02SCENNLSG2NIGYGKSSSZLZ8ZWNLYAC_1KNFQUVLYIGQZNXUOPLMPJHYCATJEWYEMNIA6RYKDP_H_ 


