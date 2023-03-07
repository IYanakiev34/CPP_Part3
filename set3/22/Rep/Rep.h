#ifndef SET3_REP_H
#define SET3_REP_H

#include <cstddef>

                              // Basically checks if the remainder needs to
                              // written as a letter or whether a "normal"
                              // number would suffix.

                              // Lowest radix: 2, since this is binary
                              // Largest radix: 36, digits: 0..9, a..z
template <size_t rem, size_t radix>
struct Rep
{
  enum
  {
                                      // This is a compiler check to ensure that
                                      // the radix is within the specified
                                      // bounds. If not, we have 1 / false
                                      // which is 1 / 0 which is a compiler
                                      // error, and thus we restrict Rep's usage
    validRadix = 1 / (radix >= 2 && radix <= 36),
                                      // whether we use should alphabet char
                                      // for representation
    isAlpha = rem > 9,
                                      // rem - 10 because because 0 .. 9 will
                                      // take up 10 digits, so to represent
                                      // n, we need the n - 10th char after
                                      // 'a'.
    rep = isAlpha ? 'a' + rem - 10 : '0' + rem
  };
};

#endif //SET3_REP_H
