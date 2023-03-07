#ifndef SET3_CHARS_H
#define SET3_CHARS_H

#include <ostream>

                              // Type promotion for a series of characters
template<char ...chars>
struct Chars
{};

template <char ...chars>
std::ostream &operator<<(std::ostream &out, Chars<chars...> charsObj)
{
                          // We unwrap chars, with each char having it's own
                          // insertion expression. Basically (though this is not
                          // valid syntax:
                          // out << chars[0], out << chars[1], ...
  ((out << chars), ...);
  return out;
}

#endif //SET3_CHARS_H
