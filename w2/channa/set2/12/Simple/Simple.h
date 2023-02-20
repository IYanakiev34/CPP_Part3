#ifndef SET2_SIMPLE_H
#define SET2_SIMPLE_H

template <typename Type>
class Simple
{
  Type d_value = Type{};

  public:
    Simple() = default;
    explicit Simple(Type const &value);

    Type &get();
};

template <typename Type>
Simple<Type>::Simple(const Type &value)
  :
  d_value(value)
{}

template <typename Type>
Type &Simple<Type>::get()
{
  return d_value;
}

#endif //SET2_SIMPLE_H
