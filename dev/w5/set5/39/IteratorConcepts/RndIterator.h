#ifndef SET5_RNDITERATOR_H
#define SET5_RNDITERATOR_H

#include "BiIterator.h"

template <typename Type>
concept Addable =
requires(Type type)
{
  {type += 0} -> std::same_as<Type &>;
  {type + 0} -> std::same_as<Type>;
};

template <typename Type>
concept Subtractable =
requires(Type type)
{
  {type -= 0} -> std::same_as<Type &>;
  {type - 0} -> std::same_as<Type>;
};

template <typename Type>
concept RndIterator =
BiIterator<Type> and Subtractable<Type> and Addable<Type>
and
requires(Type lhs, Type rhs)
{
    {lhs - rhs} -> std::convertible_to<int>;
};

#endif //SET5_RNDITERATOR_H
