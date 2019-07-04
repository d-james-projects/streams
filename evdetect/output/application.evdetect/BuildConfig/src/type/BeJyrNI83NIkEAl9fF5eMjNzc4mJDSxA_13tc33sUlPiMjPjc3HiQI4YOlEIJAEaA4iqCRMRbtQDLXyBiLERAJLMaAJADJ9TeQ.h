// y7_14YYYYMMDDhhmmss19YYYY_MM_DD_hh_mm_ss19MM_DD_YYYY_hh_mm_ss19DD_MM_YYYY_hh_mm_ss23YYYY_MM_DD_hh_mm_ss_mmm23MM_DD_YYYY_hh_mm_ss_mmm23DD_MM_YYYY_hh_mm_ss_mmm


#ifndef BEJYRNI83NIKEAL9FF5EMJNZC4MJDSXA_13TC33SULPIMJPJC3HIQI4YOLEIJAEAA4IQCRMRBTQDLXYBILERAJLMAAJADJ9TEQ_H_
#define BEJYRNI83NIKEAL9FF5EMJNZC4MJDSXA_13TC33SULPIMJPJC3HIQI4YOLEIJAEAA4IQCRMRBTQDLXYBILERAJLMAAJADJ9TEQ_H_

#include <SPL/Runtime/Type/Enum.h>

#define SELF BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ

namespace SPL {

class SELF : public Enum
{
public:
   typedef SELF Self;

   static SELF YYYYMMDDhhmmss;
   static SELF YYYY_MM_DD_hh_mm_ss;
   static SELF MM_DD_YYYY_hh_mm_ss;
   static SELF DD_MM_YYYY_hh_mm_ss;
   static SELF YYYY_MM_DD_hh_mm_ss_mmm;
   static SELF MM_DD_YYYY_hh_mm_ss_mmm;
   static SELF DD_MM_YYYY_hh_mm_ss_mmm;
   

   SELF() : Enum(*mappings_) { }
   SELF(uint32_t v) : Enum(*mappings_, v) { }
   SELF(const Self & ot) : Enum(ot) { }
   SELF(const Enum& ot) : Enum(*mappings_) { assignFrom(ot); }
   SELF(const ConstValueHandle & ot) : Enum(ot) { }
   SELF(const std::string & v);
   SELF(const rstring & v);

   virtual Enum * clone() const { return new Self(*this); }

   Self & operator=(const Self & ot) { index_ = ot.index_; return *this; }

   bool operator==(const Self & ot) const { return index_ == ot.index_; }
   bool operator!=(const Self & ot) const { return index_ != ot.index_; }
   bool operator>(const Self & ot) const { return index_ > ot.index_; }
   bool operator>=(const Self & ot) const { return index_ >= ot.index_; }
   bool operator<(const Self & ot) const { return index_ < ot.index_; }
   bool operator<=(const Self & ot) const { return index_ <= ot.index_; }

   bool operator==(const Enum & ot) const { return index_ == ot.getIndex(); }
   bool operator!=(const Enum & ot) const { return index_ != ot.getIndex(); }
   bool operator>(const Enum & ot) const { return index_ > ot.getIndex(); }
   bool operator>=(const Enum & ot) const { return index_ >= ot.getIndex(); }
   bool operator<(const Enum & ot) const { return index_ < ot.getIndex(); }
   bool operator<=(const Enum & ot) const { return index_ <= ot.getIndex(); }

   SELF& operator= (uint32_t v) { index_ = v; return *this; }

private:
   static EnumMappings* mappings_;
   static EnumMappings* initMappings();
};

// Helper for parsing CSV.
template <class T, unsigned char separator>
class CSVExtractor;

template <unsigned char separator>
class CSVExtractor<SELF, separator>
{
public:
    // Extract one token of type T from stream fs.
    static inline void extract(std::istream & fs, SELF& field) {
        field.deserialize(fs, separator);
    }
};

}  /* namespace SPL */

namespace std { 
    namespace tr1 {
        template<>
        struct hash<SPL::SELF> {
            inline size_t operator()(const SPL::SELF & self) const { return self.hashCode(); }
        };
    }
}

#undef SELF
#endif // BEJYRNI83NIKEAL9FF5EMJNZC4MJDSXA_13TC33SULPIMJPJC3HIQI4YOLEIJAEAA4IQCRMRBTQDLXYBILERAJLMAAJADJ9TEQ_H_
