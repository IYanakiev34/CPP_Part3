#ifndef SET5_BIITERATOR_H
#define SET5_BIITERATOR_H

#include "FwdIterator.h"

                            // Concept to check if the Type can be decremented
template <typename Type>
concept Decrementable =
requires(Type type)
{
  {--type} -> std::same_as<Type &>;
  {type--} -> std::same_as<Type>;
};

                              // Concept to check if the Type can work as a
                              // Bidirectional iterator
template <typename Type>
concept BiIterator =
  FwdIterator<Type> and Decrementable<Type>;

#endif //SET5_BIITERATOR_H
