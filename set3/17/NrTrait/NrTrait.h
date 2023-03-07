#ifndef SET3_NRTRAIT_H
#define SET3_NRTRAIT_H

#include <cstddef>

template <size_t val>
struct NrTrait
{
  enum
  {
    value = val,
    even = val % 2 == 0,
    by3 = val % 3 == 0,
    width = val < 10 ? 1 : 1 + NrTrait<val / 10>::width
  };
};

template<>
struct NrTrait<0>
{
  enum
  {
    value = 0,
    width = 1,
    even = true,
    by3 = false,
  };
};

#endif //SET3_NRTRAIT_H
