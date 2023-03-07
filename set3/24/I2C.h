#ifndef I2C_H
#define I2C_H

#include <cstddef>

                                // I2CAux is our workhorse class. It keeps
                                // the digits we will eventually convert to
                                // chars, in the digits parameter pack.
template <size_t val, size_t ...digits>
struct I2CAux
{
                                // We add the left most digit to the parameter
                                // pack and continue processing
  static constexpr char const *s_ntbs =
    I2CAux<(val / 10), (val % 10), digits...>::s_ntbs;
};


                    // If we have digits and we get val == 0, we just hard code
                    // the result
template <>
struct I2CAux<0>
{
  static constexpr char const s_ntbs[] = {'0', '\0'};
};

                                  // Otherwise, if we have digits
template <size_t ...digits>
struct I2CAux<0, digits...>
{
                                  // we use parameter pack expansion to
                                  // generalize the method that is in the slides
  static constexpr char const s_ntbs[] = {('0' + digits)..., '\0'};
};

                                      // I2C is a template class which converts
                                      // a size_t to a C-style string rep.
template <size_t val>
struct I2C
{
  static constexpr char const *s_ntbs = I2CAux<val>::s_ntbs;
};

#endif