#ifndef SET4_BASICMATHTEST_H
#define SET4_BASICMATHTEST_H

#include "BasicMath/BasicMath.h"

                                    // A demo template function to showcase
                                    // the BasicMath concept.
template <typename Lhs, typename Rhs>
  requires(BasicMath<Lhs, Rhs>)
auto basicMathTest(Lhs lhs, Rhs rhs)
{
  return -(lhs / (rhs - lhs)) + (lhs * rhs);
}

#endif //SET4_BASICMATHTEST_H
