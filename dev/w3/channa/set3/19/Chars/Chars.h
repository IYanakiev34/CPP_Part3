#ifndef SET3_CHARS_H
#define SET3_CHARS_H

#include <ostream>

template<char ...chars>
struct Chars
{};

template <char ...chars>
std::ostream &operator<<(std::ostream &out, Chars<chars...> charsObj)
{
  ((out << chars), ...);
  return out;
}
#endif //SET3_CHARS_H
