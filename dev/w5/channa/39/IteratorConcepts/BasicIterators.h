#ifndef SET5_BASICITERATORS_H
#define SET5_BASICITERATORS_H

#include <concepts>

                                        // Concept to check if increment op.
                                        // exists on Type
template <typename Type>
concept Incrementable =
requires(Type type)
{
  {++type} -> std::same_as<Type &>;
  {type++} -> std::same_as<Type>;
};

                              // Concept to check if dereference op.
                              // exists on Type
template <typename Type>
concept Dereferenceable =
requires(Type type)
{
  {*type} -> std::same_as<typename Type::value_type &>;
};

                              // Concept to check if dereference op.
                              // exists on Type, returning a const ref.
template <typename Type>
concept ConstDereferenceable =
requires(Type type)
{
  {*type} -> std::convertible_to<typename Type::value_type const &>;
};

                                  // Concept to check whether the Type has the
                                  // appropriate using declarations for an
                                  // iterator
template <typename Type>
concept HasIteratorUsings =
requires(Type type)
{
  typename Type::difference_type;
  typename Type::value_type;
  typename Type::pointer;
  typename Type::reference;
  typename Type::iterator_category;
};

                                // Concept to check if the Type can work as a
                                // input iterator
template <typename Type>
concept InIterator =
  std::equality_comparable<Type> and Incrementable<Type> and
  ConstDereferenceable<Type> and HasIteratorUsings<Type>;

                              // Concept to check if the Type can work as a
                              // output iterator
template <typename Type>
concept OutIterator =
  std::equality_comparable<Type> and Incrementable<Type> and
  Dereferenceable<Type> and HasIteratorUsings<Type>;

#endif //SET5_BASICITERATORS_H
