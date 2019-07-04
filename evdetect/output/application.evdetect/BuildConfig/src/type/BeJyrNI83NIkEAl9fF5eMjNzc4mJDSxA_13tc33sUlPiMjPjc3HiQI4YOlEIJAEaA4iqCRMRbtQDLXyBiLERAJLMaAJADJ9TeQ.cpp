// y7_14YYYYMMDDhhmmss19YYYY_MM_DD_hh_mm_ss19MM_DD_YYYY_hh_mm_ss19DD_MM_YYYY_hh_mm_ss23YYYY_MM_DD_hh_mm_ss_mmm23MM_DD_YYYY_hh_mm_ss_mmm23DD_MM_YYYY_hh_mm_ss_mmm


#include "BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ.h"

#define SELF BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ

using namespace SPL;

EnumMappings* SELF::mappings_ = SELF::initMappings();


SELF SELF::YYYYMMDDhhmmss(0);
SELF SELF::YYYY_MM_DD_hh_mm_ss(1);
SELF SELF::MM_DD_YYYY_hh_mm_ss(2);
SELF SELF::DD_MM_YYYY_hh_mm_ss(3);
SELF SELF::YYYY_MM_DD_hh_mm_ss_mmm(4);
SELF SELF::MM_DD_YYYY_hh_mm_ss_mmm(5);
SELF SELF::DD_MM_YYYY_hh_mm_ss_mmm(6);

SELF::SELF(const std::string & v)
: Enum(*mappings_)
{
    // initialize from a string value
    this->Enum::operator=(v);
}

SELF::SELF(const rstring & v)
: Enum(*mappings_)
{
    // initialize from a string value
    this->Enum::operator=(v);
}


EnumMappings* SELF::initMappings()
{
   EnumMappings* em = new EnumMappings();
   // initialize the mappings 
   {
      std::string s("YYYYMMDDhhmmss");
      em->nameToIndex_.insert(std::make_pair(s, 0));
      em->indexToName_.push_back(s);
   }
   
   {
      std::string s("YYYY_MM_DD_hh_mm_ss");
      em->nameToIndex_.insert(std::make_pair(s, 1));
      em->indexToName_.push_back(s);
   }
   
   {
      std::string s("MM_DD_YYYY_hh_mm_ss");
      em->nameToIndex_.insert(std::make_pair(s, 2));
      em->indexToName_.push_back(s);
   }
   
   {
      std::string s("DD_MM_YYYY_hh_mm_ss");
      em->nameToIndex_.insert(std::make_pair(s, 3));
      em->indexToName_.push_back(s);
   }
   
   {
      std::string s("YYYY_MM_DD_hh_mm_ss_mmm");
      em->nameToIndex_.insert(std::make_pair(s, 4));
      em->indexToName_.push_back(s);
   }
   
   {
      std::string s("MM_DD_YYYY_hh_mm_ss_mmm");
      em->nameToIndex_.insert(std::make_pair(s, 5));
      em->indexToName_.push_back(s);
   }
   
   {
      std::string s("DD_MM_YYYY_hh_mm_ss_mmm");
      em->nameToIndex_.insert(std::make_pair(s, 6));
      em->indexToName_.push_back(s);
   }
   
   return em;
}
