#ifndef SET5_CONCEPTS_H
#define SET5_CONCEPTS_H

template <typename Type>
concept Add =
requires(Type lhs, Type rhs)
{
  rhs + lhs;
  rhs - lhs;
};

template <typename Type>
concept Mul =
requires(Type lhs, Type rhs)
{
  rhs * lhs;
  rhs / lhs;
};

template <typename Type>
concept AddMul = Add<Type> or Mul<Type>;

template <typename Type>
concept AddOrMul =
(Add<Type> and not Mul<Type>) or
(Mul<Type> and not Add<Type>);

#endif //SET5_CONCEPTS_H
