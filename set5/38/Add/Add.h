#ifndef SET5_ADD_H
#define SET5_ADD_H

#include "../BasicMath/BasicMath.h"

#include <iostream>

                                  // Struct that defines an operation static
                                  // function that operates on two
                                  // operands that must support BasicMath.
                                  // The operation uses addition.
template <typename Lhs, typename Rhs>
  requires BasicMath<Lhs, Rhs>
struct Add
{
  static void operation(Lhs lhs, Rhs rhs);
};

                            // Output the result of addition of lhs, rhs to
                            // cout.
template <typename Lhs, typename Rhs>
  requires BasicMath<Lhs, Rhs>
void Add<Lhs, Rhs>::operation(Lhs lhs, Rhs rhs)
{
  std::cout << (lhs + rhs) << ' ';
}

#endif //SET5_ADD_H
