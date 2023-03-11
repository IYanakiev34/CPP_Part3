#ifndef SET4_BASICMATH_H
#define SET4_BASICMATH_H

                        // Concept that ensures that two types have basic
                        // binary math operators established in one direction
                        // i.e: not rhs op lhs.
template <typename Lhs, typename Rhs>
concept BinaryMath =
  requires(Lhs lhs, Rhs rhs){
    lhs + rhs;
    lhs - rhs;
    lhs * rhs;
    lhs / rhs;
  };

                        // Concept that basic math operators exist between two
                        // types, with either type being used as the Lhs
template <typename Type1, typename Type2>
concept BasicMath =
                        // Check binary operations work in either dir.
  BinaryMath<Type1, Type2> and BinaryMath<Type2, Type1> and
  requires(Type1 type1, Type2 type2)
  {
                        // Check unary ops.
    -type1;
    -type2;
  };

#endif //SET4_BASICMATH_H
