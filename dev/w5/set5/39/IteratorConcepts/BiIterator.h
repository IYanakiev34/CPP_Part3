#ifndef SET5_BIITERATOR_H
#define SET5_BIITERATOR_H

#include "FwdIterator.h"

template <typename Type>
concept Decrementable =
requires(Type type)
{
  {--type} -> std::same_as<Type &>;
  {type--} -> std::same_as<Type>;
};

template <typename Type>
concept BiIterator =
FwdIterator<Type> and Decrementable<Type>;

#endif //SET5_BIITERATOR_H
