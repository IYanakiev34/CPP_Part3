#ifndef SET3_BIN_H
#define SET3_BIN_H

#include <cstddef>

                                    // Bin is a template class that converts
                                    // an decimal value into "binary" value,
                                    // held in the enum: binary.

                                    // value is an integer but it visually
                                    // looks like the corresponding binary num.
template <size_t val>
struct Bin
{
  enum
  {
                                    // We compute the rightmost bit of val via
                                    // val % 2. The rest of the binary would
                                    // then be in val >> 1. We then compute the
                                    // rest of the binary via
                                    // Bin<(val >> 1)>::value, which we multiply
                                    // by 10 to put leftmost rest in the right
                                    // decimal place.
    value = Bin<(val >> 1)>::value * 10 + val % 2
  };
};

                                    // Base case: val = 0, "binary" is also 0
template <>
struct Bin<0>
{
  enum
  {
    value = 0
  };
};

#endif //SET3_BIN_H
