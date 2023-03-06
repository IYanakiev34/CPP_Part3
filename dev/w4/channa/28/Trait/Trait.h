#ifndef SET4_TRAIT_H
#define SET4_TRAIT_H

template <typename Type>
struct Trait
{
  enum
  {
    value = 1
  };
};

template <typename Type>
struct Trait<Type *>
{
  enum
  {
    value = 2
  };
};

template <typename Type>
struct Trait<Type &>
{
  enum
  {
    value = 3
  };
};
template <typename Type>
struct Trait<Type &&>
{
  enum
  {
    value = 4
  };
};

#endif //SET4_TRAIT_H
