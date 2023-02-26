#ifndef SET3_I2C_H
#define SET3_I2C_H

#include "I2CAux.h"

                                    // I2C essentially acts as a wrapper for
                                    // I2CAux, which is the workhorse.
template <size_t num>
struct I2C
{
  static constexpr char const *s_ntbs = I2CAux<num, true, 1>::s_chars;
};

                                  // Manually handle the case where num == 0
                                  // since I2CAux uses that as a sentinel value
template <>
struct I2C<0>
{
  static constexpr char const s_ntbs[] = {'0', 0};
};


#endif //SET3_I2C_H
