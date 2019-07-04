// t9s11stationCodeI15observationTimef4tempf7tempInFf16relativeHumidityf8dewpointk18windHeadingDegreesk14windSpeedKnotsk13windGustKnots


#include "BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h"
#include <sstream>

#define SELF BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy

using namespace SPL;

TupleMappings* SELF::mappings_ = SELF::initMappings();

static void addMapping(TupleMappings & tm, TypeOffset & offset,
                       std::string const & name, uint32_t index)
{
    tm.nameToIndex_.insert(std::make_pair(name, index)); 
    tm.indexToName_.push_back(name);
    tm.indexToTypeOffset_.push_back(offset);    
}

static Tuple * initer() { return new SELF(); }

TupleMappings* SELF::initMappings()
{
    instantiators_.insert(std::make_pair("tuple<rstring stationCode,int64 observationTime,float32 temp,float32 tempInF,float32 relativeHumidity,float32 dewpoint,int16 windHeadingDegrees,int16 windSpeedKnots,int16 windGustKnots>",&initer));
    TupleMappings * tm = new TupleMappings();
#define MY_OFFSETOF(member, base) \
    ((uintptr_t)&reinterpret_cast<Self*>(base)->member) - (uintptr_t)base
   
    // initialize the mappings 
    
    {
        std::string s("stationCode");
        TypeOffset t(MY_OFFSETOF(stationCode_, tm), 
                     Meta::Type::typeOf<SPL::rstring >(), 
                     &typeid(SPL::rstring));
        addMapping(*tm, t, s, 0);
    }
    
    {
        std::string s("observationTime");
        TypeOffset t(MY_OFFSETOF(observationTime_, tm), 
                     Meta::Type::typeOf<SPL::int64 >(), 
                     &typeid(SPL::int64));
        addMapping(*tm, t, s, 1);
    }
    
    {
        std::string s("temp");
        TypeOffset t(MY_OFFSETOF(temp_, tm), 
                     Meta::Type::typeOf<SPL::float32 >(), 
                     &typeid(SPL::float32));
        addMapping(*tm, t, s, 2);
    }
    
    {
        std::string s("tempInF");
        TypeOffset t(MY_OFFSETOF(tempInF_, tm), 
                     Meta::Type::typeOf<SPL::float32 >(), 
                     &typeid(SPL::float32));
        addMapping(*tm, t, s, 3);
    }
    
    {
        std::string s("relativeHumidity");
        TypeOffset t(MY_OFFSETOF(relativeHumidity_, tm), 
                     Meta::Type::typeOf<SPL::float32 >(), 
                     &typeid(SPL::float32));
        addMapping(*tm, t, s, 4);
    }
    
    {
        std::string s("dewpoint");
        TypeOffset t(MY_OFFSETOF(dewpoint_, tm), 
                     Meta::Type::typeOf<SPL::float32 >(), 
                     &typeid(SPL::float32));
        addMapping(*tm, t, s, 5);
    }
    
    {
        std::string s("windHeadingDegrees");
        TypeOffset t(MY_OFFSETOF(windHeadingDegrees_, tm), 
                     Meta::Type::typeOf<SPL::int16 >(), 
                     &typeid(SPL::int16));
        addMapping(*tm, t, s, 6);
    }
    
    {
        std::string s("windSpeedKnots");
        TypeOffset t(MY_OFFSETOF(windSpeedKnots_, tm), 
                     Meta::Type::typeOf<SPL::int16 >(), 
                     &typeid(SPL::int16));
        addMapping(*tm, t, s, 7);
    }
    
    {
        std::string s("windGustKnots");
        TypeOffset t(MY_OFFSETOF(windGustKnots_, tm), 
                     Meta::Type::typeOf<SPL::int16 >(), 
                     &typeid(SPL::int16));
        addMapping(*tm, t, s, 8);
    }
    
    return tm;
}

void SELF::deserialize(std::istream & istr, bool withSuffix)
{
   std::string s;
   char c;

   istr >> c; if (!istr) { return; }
   if (c != '{') { istr.setstate(std::ios_base::failbit); return; }
   
   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "stationCode") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, stationCode_);
   else
     istr >> stationCode_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "observationTime") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, observationTime_);
   else
     istr >> observationTime_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "temp") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, temp_);
   else
     istr >> temp_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "tempInF") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, tempInF_);
   else
     istr >> tempInF_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "relativeHumidity") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, relativeHumidity_);
   else
     istr >> relativeHumidity_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "dewpoint") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, dewpoint_);
   else
     istr >> dewpoint_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "windHeadingDegrees") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, windHeadingDegrees_);
   else
     istr >> windHeadingDegrees_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "windSpeedKnots") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, windSpeedKnots_);
   else
     istr >> windSpeedKnots_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "windGustKnots") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, windGustKnots_);
   else
     istr >> windGustKnots_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   
   if (c != '}') { istr.setstate(std::ios_base::failbit); return; }
}

void SELF::deserializeWithNanAndInfs(std::istream & istr, bool withSuffix)
{
   std::string s;
   char c;

   istr >> c; if (!istr) { return; }
   if (c != '{') { istr.setstate(std::ios_base::failbit); return; }
   
   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "stationCode") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, stationCode_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "observationTime") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, observationTime_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "temp") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, temp_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "tempInF") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, tempInF_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "relativeHumidity") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, relativeHumidity_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "dewpoint") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, dewpoint_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "windHeadingDegrees") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, windHeadingDegrees_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "windSpeedKnots") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, windSpeedKnots_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "windGustKnots") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, windGustKnots_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   
   if (c != '}') { istr.setstate(std::ios_base::failbit); return; }
}

void SELF::serialize(std::ostream & ostr) const
{
    ostr << '{'
         << "stationCode=" << get_stationCode()  << ","
         << "observationTime=" << get_observationTime()  << ","
         << "temp=" << get_temp()  << ","
         << "tempInF=" << get_tempInF()  << ","
         << "relativeHumidity=" << get_relativeHumidity()  << ","
         << "dewpoint=" << get_dewpoint()  << ","
         << "windHeadingDegrees=" << get_windHeadingDegrees()  << ","
         << "windSpeedKnots=" << get_windSpeedKnots()  << ","
         << "windGustKnots=" << get_windGustKnots()  
         << '}';
}

void SELF::serializeWithPrecision(std::ostream & ostr) const
{
    ostr << '{';
    SPL::serializeWithPrecision(ostr << "stationCode=", get_stationCode()) << ",";
    SPL::serializeWithPrecision(ostr << "observationTime=", get_observationTime()) << ",";
    SPL::serializeWithPrecision(ostr << "temp=", get_temp()) << ",";
    SPL::serializeWithPrecision(ostr << "tempInF=", get_tempInF()) << ",";
    SPL::serializeWithPrecision(ostr << "relativeHumidity=", get_relativeHumidity()) << ",";
    SPL::serializeWithPrecision(ostr << "dewpoint=", get_dewpoint()) << ",";
    SPL::serializeWithPrecision(ostr << "windHeadingDegrees=", get_windHeadingDegrees()) << ",";
    SPL::serializeWithPrecision(ostr << "windSpeedKnots=", get_windSpeedKnots()) << ",";
    SPL::serializeWithPrecision(ostr << "windGustKnots=", get_windGustKnots()) ;
    ostr << '}';
}

SELF& SELF::clear()
{
    SPL::rstring().swap(get_stationCode());
    get_observationTime() = 0;
    get_temp() = 0;
    get_tempInF() = 0;
    get_relativeHumidity() = 0;
    get_dewpoint() = 0;
    get_windHeadingDegrees() = 0;
    get_windSpeedKnots() = 0;
    get_windGustKnots() = 0;

    return *this;
}

void SELF::normalizeBoundedSetsAndMaps()
{
    SPL::normalizeBoundedSetsAndMaps(*this);
}


