#ifndef SET3_REP_H
#define SET3_REP_H

#include <cstddef>

                              // Basically checks if the remainder needs to
                              // written as a letter or whether a "normal"
                              // number would suffix
template <size_t rem, size_t radix>
struct Rep
{
  enum
  {
    alpha = rem > 9,
    rep = alpha ? 'a' + rem - 10 : '0' + rem
  };
};

#endif //SET3_REP_H
