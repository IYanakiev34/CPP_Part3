#ifndef SET3_I2CAUX_H
#define SET3_I2CAUX_H

#include <cstddef>

                              // The idea here is that we want to store the
                              // powers we in the parameter pack expansion
                              // expression in a variadic template list.

                              // We have a bool cont which is what we use
                              // to signal that we have enough powers and we
                              // should go to the base case.
template <size_t num, bool cont, size_t largestPow, size_t ...otherPow>
struct I2CAux
{
                                  // We add another power of 10 to our list of
                                  // powers. We know we have to stop when
                                  // largestPow > num, since that guarantees
                                  // that the power we add will have one more
                                  // digit than num.
  static constexpr char const *s_chars =
    I2CAux<num, (num > largestPow), largestPow*10, largestPow, otherPow...>
    ::s_chars;
};

                                // In the base case, we generalize the method
                                // in the week 3 lecture (slide 6) via
                                // parameter pack expansion.
template <size_t num, size_t largest, size_t nextLargest, size_t ...pows>
struct I2CAux<num, false, largest, nextLargest, pows...>
{
  static constexpr char const s_chars[] = {
    ('0' + (num / pows % 10))...,
    0
  };

};

#endif //SET3_I2CAUX_H
