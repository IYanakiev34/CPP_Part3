//JB: ?
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
inline Simple<Type>::Simple(const Type &value)
  :
  d_value(value)
{}

template <typename Type>
inline Type &Simple<Type>::get()
{
  return d_value;
}

#endif //SET2_SIMPLE_H
/* JB: Please fix:
   I'd expect to be able to use Simple when I include this header.
   However, the specialization won't then be used.
 */
