#ifndef SET4_TRAIT_H
#define SET4_TRAIT_H

                              // This is a trait class used to determine whether
                              // a Type is a plain type, a pointer type, a
                              // lvalue reference or a rvalue reference.

                              // Puts 1,2,3,4 in value, respectively

template <typename Type>
struct Trait
{
  using BasicType = Type;
  enum
  {
    value = 1
  };
};

template <typename Type>
struct Trait<Type *>
{
  using BasicType = Type;
  enum
  {
    value = 2
  };
};

template <typename Type>
struct Trait<Type &>
{
  using BasicType = Type;
  enum
  {
    value = 3
  };
};
template <typename Type>
struct Trait<Type &&>
{
  using BasicType = Type;
  enum
  {
    value = 4
  };
};

#endif //SET4_TRAIT_H
