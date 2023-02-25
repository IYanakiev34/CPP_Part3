#ifndef SET3_BIN_H
#define SET3_BIN_H

#include <cstddef>

template <size_t val, size_t ...Bits>
struct Bin
{
  static constexpr char const *value =
    Bin<(val >> 1), (val & 1ull ? 1ull : 0ull), Bits...>::value;
};

template<size_t ...Bits>
struct Bin<0, Bits...>
{
  static constexpr char const value[] = {('0' + Bits)..., '\0'};
};

#endif //SET3_BIN_H
