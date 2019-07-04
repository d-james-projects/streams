// t8s11stationCodeI15observationTimef4tempf8dewpointk17pressureMillibarsk18windHeadingDegreesk14windSpeedKnotsk13windGustKnots


#ifndef BEJWDYEEOGKAMBDAZNWKCVSROJCU9WJB_0SANMJ22R6WSS34VKRB45RMTDGU_06AU_0W3ZLFWTA0GAUOIBFVLRIT3ARBFTW8ZZ6LZ_0YTPU0KP5BZYTHINGDP5SHPBFHVNPA4HNGTHQF_1L9IVDW_H_
#define BEJWDYEEOGKAMBDAZNWKCVSROJCU9WJB_0SANMJ22R6WSS34VKRB45RMTDGU_06AU_0W3ZLFWTA0GAUOIBFVLRIT3ARBFTW8ZZ6LZ_0YTPU0KP5BZYTHINGDP5SHPBFHVNPA4HNGTHQF_1L9IVDW_H_

#include <SPL/Runtime/Type/Tuple.h>
#include <SPL/Runtime/Type/PrimitiveType.h>
#include <SPL/Runtime/Type/CollectionType.h>
#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Serialization/NativeByteBuffer.h>
#include <SPL/Runtime/Serialization/VirtualByteBuffer.h>
#include <SPL/Runtime/Type/Optional.h>
#include <SPL/Runtime/Utility/TimeUtils.h>



#define SELF BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW

namespace SPL {

class SELF : public Tuple
{
public:
    static const bool facade = false;

    typedef SELF Self;
    
    typedef SPL::rstring stationCode_type;
    typedef SPL::int64 observationTime_type;
    typedef SPL::float32 temp_type;
    typedef SPL::float32 dewpoint_type;
    typedef SPL::int16 pressureMillibars_type;
    typedef SPL::int16 windHeadingDegrees_type;
    typedef SPL::int16 windSpeedKnots_type;
    typedef SPL::int16 windGustKnots_type;

    enum { num_attributes = 8 } ;
    
    SELF() : Tuple(), stationCode_(), observationTime_(), temp_(), dewpoint_(), pressureMillibars_(), windHeadingDegrees_(), windSpeedKnots_(), windGustKnots_() {}
    SELF(const Self & ot) : Tuple(), stationCode_(ot.stationCode_), observationTime_(ot.observationTime_), temp_(ot.temp_), dewpoint_(ot.dewpoint_), pressureMillibars_(ot.pressureMillibars_), windHeadingDegrees_(ot.windHeadingDegrees_), windSpeedKnots_(ot.windSpeedKnots_), windGustKnots_(ot.windGustKnots_) 
      { constructPayload(ot); }
    SELF(const stationCode_type & _stationCode, const observationTime_type & _observationTime, const temp_type & _temp, const dewpoint_type & _dewpoint, const pressureMillibars_type & _pressureMillibars, const windHeadingDegrees_type & _windHeadingDegrees, const windSpeedKnots_type & _windSpeedKnots, const windGustKnots_type & _windGustKnots) : Tuple(), stationCode_(_stationCode), observationTime_(_observationTime), temp_(_temp), dewpoint_(_dewpoint), pressureMillibars_(_pressureMillibars), windHeadingDegrees_(_windHeadingDegrees), windSpeedKnots_(_windSpeedKnots), windGustKnots_(_windGustKnots) { }
    
    SELF(const Tuple & ot, bool typesafe = true) : Tuple() { assignFrom(ot, typesafe); }
    SELF(const ConstValueHandle & ot) : Tuple() { const Tuple & o = ot; assignFrom(o); }

    virtual ~SELF() {}
    
    stationCode_type & get_stationCode() { return stationCode_; }
    const stationCode_type & get_stationCode() const { return stationCode_; }
    void set_stationCode(const stationCode_type & _stationCode) { stationCode_ = _stationCode; }
    observationTime_type & get_observationTime() { return observationTime_; }
    const observationTime_type & get_observationTime() const { return observationTime_; }
    void set_observationTime(const observationTime_type & _observationTime) { observationTime_ = _observationTime; }
    temp_type & get_temp() { return temp_; }
    const temp_type & get_temp() const { return temp_; }
    void set_temp(const temp_type & _temp) { temp_ = _temp; }
    dewpoint_type & get_dewpoint() { return dewpoint_; }
    const dewpoint_type & get_dewpoint() const { return dewpoint_; }
    void set_dewpoint(const dewpoint_type & _dewpoint) { dewpoint_ = _dewpoint; }
    pressureMillibars_type & get_pressureMillibars() { return pressureMillibars_; }
    const pressureMillibars_type & get_pressureMillibars() const { return pressureMillibars_; }
    void set_pressureMillibars(const pressureMillibars_type & _pressureMillibars) { pressureMillibars_ = _pressureMillibars; }
    windHeadingDegrees_type & get_windHeadingDegrees() { return windHeadingDegrees_; }
    const windHeadingDegrees_type & get_windHeadingDegrees() const { return windHeadingDegrees_; }
    void set_windHeadingDegrees(const windHeadingDegrees_type & _windHeadingDegrees) { windHeadingDegrees_ = _windHeadingDegrees; }
    windSpeedKnots_type & get_windSpeedKnots() { return windSpeedKnots_; }
    const windSpeedKnots_type & get_windSpeedKnots() const { return windSpeedKnots_; }
    void set_windSpeedKnots(const windSpeedKnots_type & _windSpeedKnots) { windSpeedKnots_ = _windSpeedKnots; }
    windGustKnots_type & get_windGustKnots() { return windGustKnots_; }
    const windGustKnots_type & get_windGustKnots() const { return windGustKnots_; }
    void set_windGustKnots(const windGustKnots_type & _windGustKnots) { windGustKnots_ = _windGustKnots; }
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
        buf << stationCode_ << observationTime_ << temp_ << dewpoint_ << pressureMillibars_ << windHeadingDegrees_ << windSpeedKnots_ << windGustKnots_;
    }

    template <class BufferType>
    void serialize(ByteBuffer<BufferType> & buf) const
    {        
        buf << stationCode_ << observationTime_ << temp_ << dewpoint_ << pressureMillibars_ << windHeadingDegrees_ << windSpeedKnots_ << windGustKnots_;
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
        buf >> stationCode_ >> observationTime_ >> temp_ >> dewpoint_ >> pressureMillibars_ >> windHeadingDegrees_ >> windSpeedKnots_ >> windGustKnots_;
    }

    template <class BufferType>
    void deserialize(ByteBuffer<BufferType> & buf)
    {        
        buf >> stationCode_ >> observationTime_ >> temp_ >> dewpoint_ >> pressureMillibars_ >> windHeadingDegrees_ >> windSpeedKnots_ >> windGustKnots_;
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
        s = 37 * s + std::tr1::hash<stationCode_type >()(stationCode_);
        s = 37 * s + std::tr1::hash<observationTime_type >()(observationTime_);
        s = 37 * s + std::tr1::hash<temp_type >()(temp_);
        s = 37 * s + std::tr1::hash<dewpoint_type >()(dewpoint_);
        s = 37 * s + std::tr1::hash<pressureMillibars_type >()(pressureMillibars_);
        s = 37 * s + std::tr1::hash<windHeadingDegrees_type >()(windHeadingDegrees_);
        s = 37 * s + std::tr1::hash<windSpeedKnots_type >()(windSpeedKnots_);
        s = 37 * s + std::tr1::hash<windGustKnots_type >()(windGustKnots_);
        return s;
    }
    
    size_t getSerializedSize() const
    {
        size_t size = sizeof(SPL::int64)+sizeof(SPL::float32)+sizeof(SPL::float32)+sizeof(SPL::int16)+sizeof(SPL::int16)+sizeof(SPL::int16)+sizeof(SPL::int16);
           size += stationCode_.getSerializedSize();

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
        stationCode_ = ot.stationCode_;
        observationTime_ = ot.observationTime_;
        temp_ = ot.temp_;
        dewpoint_ = ot.dewpoint_;
        pressureMillibars_ = ot.pressureMillibars_;
        windHeadingDegrees_ = ot.windHeadingDegrees_;
        windSpeedKnots_ = ot.windSpeedKnots_;
        windGustKnots_ = ot.windGustKnots_; 
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
                stationCode_ == ot.stationCode_ && 
                observationTime_ == ot.observationTime_ && 
                temp_ == ot.temp_ && 
                dewpoint_ == ot.dewpoint_ && 
                pressureMillibars_ == ot.pressureMillibars_ && 
                windHeadingDegrees_ == ot.windHeadingDegrees_ && 
                windSpeedKnots_ == ot.windSpeedKnots_ && 
                windGustKnots_ == ot.windGustKnots_  
              ); 
    }
    bool operator==(const Tuple & ot) const { return equals(ot); }

    bool operator!=(const Self & ot) const { return !(*this == ot); }
    bool operator!=(const Tuple & ot) const { return !(*this == ot); }


    void swap(SELF & ot) 
    { 
        std::swap(stationCode_, ot.stationCode_);
        std::swap(observationTime_, ot.observationTime_);
        std::swap(temp_, ot.temp_);
        std::swap(dewpoint_, ot.dewpoint_);
        std::swap(pressureMillibars_, ot.pressureMillibars_);
        std::swap(windHeadingDegrees_, ot.windHeadingDegrees_);
        std::swap(windSpeedKnots_, ot.windSpeedKnots_);
        std::swap(windGustKnots_, ot.windGustKnots_);
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
    
    stationCode_type stationCode_;
    observationTime_type observationTime_;
    temp_type temp_;
    dewpoint_type dewpoint_;
    pressureMillibars_type pressureMillibars_;
    windHeadingDegrees_type windHeadingDegrees_;
    windSpeedKnots_type windSpeedKnots_;
    windGustKnots_type windGustKnots_;

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
#endif // BEJWDYEEOGKAMBDAZNWKCVSROJCU9WJB_0SANMJ22R6WSS34VKRB45RMTDGU_06AU_0W3ZLFWTA0GAUOIBFVLRIT3ARBFTW8ZZ6LZ_0YTPU0KP5BZYTHINGDP5SHPBFHVNPA4HNGTHQF_1L9IVDW_H_ 


