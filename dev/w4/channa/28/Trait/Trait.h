#ifndef SET4_TRAIT_H
#define SET4_TRAIT_H

                              // This is a trait class used to determine whether
                              // a Type is a plain type, a pointer type, a
                              // lvalue reference or a rvalue reference.

                              // Puts 1,2,3,4 in value, respectively
enum
{
  PLAIN = 1,
  POINTER,
  LVALUE,
  RVALUE
};

template <typename Type>
struct Trait
{
  enum
  {
    value = PLAIN
  };
};

template <typename Type>
struct Trait<Type *>
{
  enum
  {
    value = POINTER
  };
};

template <typename Type>
struct Trait<Type &>
{
  enum
  {
    value = LVALUE
  };
};
template <typename Type>
struct Trait<Type &&>
{
  enum
  {
    value = RVALUE
  };
};

#endif //SET4_TRAIT_H
