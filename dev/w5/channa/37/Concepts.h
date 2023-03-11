#ifndef SET5_CONCEPTS_H
#define SET5_CONCEPTS_H

                          // Concept that checks that Type works with
                          // addition / subtraction.
template <typename Type>
concept Add =
requires(Type lhs, Type rhs)
{
  lhs + rhs;
  lhs - rhs;
};

                              // Concept that checks that Type works with
                              // multiplication / division.
template <typename Type>
concept Mul =
requires(Type lhs, Type rhs)
{
  rhs * lhs;
  rhs / lhs;
};

                          // A concept that checks whether Type support
                          // Addition / Multiplication / both.
template <typename Type>
concept AddMul = Add<Type> or Mul<Type>;

                          // A concept that checks whether Type supports
                          // Addition / Multiplication (and only one).
template <typename Type>
concept AddOrMul =
(Add<Type> and not Mul<Type>) or
(Mul<Type> and not Add<Type>);

#endif //SET5_CONCEPTS_H
