#ifndef SET4_BASICMATHTEST_H
#define SET4_BASICMATHTEST_H

#include "BasicMath/BasicMath.h"

template <typename Lhs, typename Rhs>
  requires(BasicMath<Lhs, Rhs>)
auto basicMathTest(Lhs lhs, Rhs rhs)
{
  return -(lhs / (rhs - lhs)) + (lhs * rhs);
}

#endif //SET4_BASICMATHTEST_H
