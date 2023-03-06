#ifndef SET4_PLUS_H
#define SET4_PLUS_H

template <typename Type>
struct plus
{
  Type operator()(Type const &lhs, Type const &rhs) const;
};

template<typename Type>
Type plus<Type>::operator()(const Type &lhs, const Type &rhs) const
{
  return lhs + rhs;
}

#endif //SET4_PLUS_H
