#ifndef SET5_BASICITERATORS_H
#define SET5_BASICITERATORS_H

#include <concepts>
template <typename Type>
concept Incrementable =
requires(Type type)
{
  {++type} -> std::same_as<Type &>;
  {type++} -> std::same_as<Type>;
};

template <typename Type>
concept Dereferenceable =
requires(Type type)
{
  {*type} -> std::same_as<typename Type::value_type &>;
};

template <typename Type>
concept ConstDereferenceable =
requires(Type type)
{
  {*type} -> std::convertible_to<typename Type::value_type const &>;
};

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

template <typename Type>
concept InIterator =
std::equality_comparable<Type> and Incrementable<Type> and
ConstDereferenceable<Type> and HasIteratorUsings<Type>;

template <typename Type>
concept OutIterator =
std::equality_comparable<Type> and Incrementable<Type> and
Dereferenceable<Type> and HasIteratorUsings<Type>;

#endif //SET5_BASICITERATORS_H
