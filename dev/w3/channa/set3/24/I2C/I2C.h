#ifndef SET3_I2C_H
#define SET3_I2C_H

#include <cstddef>

template <size_t num, bool cont, size_t largestPow, size_t ...otherPow>
struct I2CAux
{
  static constexpr char const *s_chars =
    I2CAux<num, (num > largestPow), largestPow*10, largestPow, otherPow...>
      ::s_chars;
};

template <size_t num, size_t largest, size_t nextLargest, size_t ...pows>
struct I2CAux<num, false, largest, nextLargest, pows...>
{
  static constexpr char const s_chars[] = {
    ('0' + (num / pows % 10))...,
    0
  };

};

template <size_t num>
struct I2C
{
  static constexpr char const *s_ntbs = I2CAux<num, true, 1>::s_chars;
};

template <>
struct I2C<0>
{
  static constexpr char const s_ntbs[] = {'0', 0};
};


#endif //SET3_I2C_H
