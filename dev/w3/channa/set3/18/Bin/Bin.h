#ifndef SET3_BIN_H
#define SET3_BIN_H

#include <cstddef>

                              // The idea is to store the binary representation
                              // in the bits variadic template parameter.

                              // cont keeps track of whether we have to keep
                              // adding to bits, or if we write the actual
                              // expression out.
template <size_t val, bool cont = true, size_t ...bits>
struct Bin
{
                                // Every step down the template instantiation
                                // we determine the right-most bit and add it
                                // to the front of the existing bits (since bits
                                // would contain all bits after the current
                                // bit)
  enum
  {
    afterShift = val >> 1
  };
  static constexpr char const *value =
    Bin<afterShift, afterShift!= 0, (val & 1ull ? 1ull : 0ull), bits...>::value;
};

template<size_t val, size_t ...bits>
struct Bin<val, false, bits...>
{
                                // In the base case where we have evaluated
                                // all the bits, we actually write the
                                // value into the static constexpr.
  static constexpr char const value[] = {('0' + bits)..., '\0'};
};

#endif //SET3_BIN_H
