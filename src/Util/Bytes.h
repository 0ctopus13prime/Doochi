#ifndef LUCENE_CORE_UTIL_BYTES_H_
#define LUCENE_CORE_UTIL_BYTES_H_

#include <string>

namespace lucene { namespace core { namespace util {

class BytesRef final {
  private:
    int CompareTo(BytesRef& other);

  public:
    static char BYTES_REF_EMPTY_BYTES[1];
    char* bytes;
    unsigned int offset;
    unsigned int length;

  public:
    BytesRef();
    BytesRef(char* bytes, unsigned int offset, unsigned int length);
    // It's a shallow copy, not a deep copy.
    BytesRef(const BytesRef& other);
    static void DeepCopyOf(BytesRef& source, BytesRef& target);
    BytesRef(unsigned int capacity);
    BytesRef(std::string& text);
    ~BytesRef();
    bool operator==(BytesRef& other);
    bool operator!=(BytesRef& other);
    bool operator<(BytesRef& other);
    bool operator<=(BytesRef& other);
    bool operator>(BytesRef& other);
    bool operator>=(BytesRef& other);
    std::string UTF8ToString();
    bool IsValid();
};
char BytesRef::BYTES_REF_EMPTY_BYTES[1] = {'\0'};

}}} // End of namespace

#endif
