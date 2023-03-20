#ifndef SET4_BASICMATH_H
#define SET4_BASICMATH_H

template <typename Lhs, typename Rhs>
concept BasicMath =
  requires(Lhs lhs, Rhs rhs){
    rhs + lhs;
    lhs + rhs;

    rhs - lhs;
    lhs - rhs;

    rhs * lhs;
    lhs * rhs;

    rhs / lhs;
    lhs / rhs;

    -lhs;
    -rhs;
  };

#endif //SET4_BASICMATH_H
