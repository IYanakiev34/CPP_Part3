#ifndef SET3_REP_H
#define SET3_REP_H

#include <cstddef>

template <size_t num, size_t radix>
struct Rep
{
  enum
  {
    rem = num % radix,
    alpha = rem > 9,
    rep = alpha ? 'a' + rem - 10 : '0' + rem
  };
};

#endif //SET3_REP_H
