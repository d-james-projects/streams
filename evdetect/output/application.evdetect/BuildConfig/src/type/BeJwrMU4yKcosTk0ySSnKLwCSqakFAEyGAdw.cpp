// t3b4riseb4dropb4deep


#include "BeJwrMU4yKcosTk0ySSnKLwCSqakFAEyGAdw.h"
#include <sstream>

#define SELF BeJwrMU4yKcosTk0ySSnKLwCSqakFAEyGAdw

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
    instantiators_.insert(std::make_pair("tuple<boolean rise,boolean drop,boolean deep>",&initer));
    TupleMappings * tm = new TupleMappings();
#define MY_OFFSETOF(member, base) \
    ((uintptr_t)&reinterpret_cast<Self*>(base)->member) - (uintptr_t)base
   
    // initialize the mappings 
    
    {
        std::string s("rise");
        TypeOffset t(MY_OFFSETOF(rise_, tm), 
                     Meta::Type::typeOf<SPL::boolean >(), 
                     &typeid(SPL::boolean));
        addMapping(*tm, t, s, 0);
    }
    
    {
        std::string s("drop");
        TypeOffset t(MY_OFFSETOF(drop_, tm), 
                     Meta::Type::typeOf<SPL::boolean >(), 
                     &typeid(SPL::boolean));
        addMapping(*tm, t, s, 1);
    }
    
    {
        std::string s("deep");
        TypeOffset t(MY_OFFSETOF(deep_, tm), 
                     Meta::Type::typeOf<SPL::boolean >(), 
                     &typeid(SPL::boolean));
        addMapping(*tm, t, s, 2);
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
   if (s != "rise") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, rise_);
   else
     istr >> rise_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "drop") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, drop_);
   else
     istr >> drop_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "deep") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, deep_);
   else
     istr >> deep_;
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
   if (s != "rise") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, rise_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "drop") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, drop_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "deep") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, deep_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   
   if (c != '}') { istr.setstate(std::ios_base::failbit); return; }
}

void SELF::serialize(std::ostream & ostr) const
{
    ostr << '{'
         << "rise=" << get_rise()  << ","
         << "drop=" << get_drop()  << ","
         << "deep=" << get_deep()  
         << '}';
}

void SELF::serializeWithPrecision(std::ostream & ostr) const
{
    ostr << '{';
    SPL::serializeWithPrecision(ostr << "rise=", get_rise()) << ",";
    SPL::serializeWithPrecision(ostr << "drop=", get_drop()) << ",";
    SPL::serializeWithPrecision(ostr << "deep=", get_deep()) ;
    ostr << '}';
}

SELF& SELF::clear()
{
    get_rise() = false;
    get_drop() = false;
    get_deep() = false;

    return *this;
}

void SELF::normalizeBoundedSetsAndMaps()
{
    SPL::normalizeBoundedSetsAndMaps(*this);
}


