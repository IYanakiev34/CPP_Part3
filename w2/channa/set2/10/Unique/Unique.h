#ifndef SET1_UNIQUE_H
#define SET1_UNIQUE_H

#include <memory>

template <typename Type>
class Unique
{
  std::unique_ptr<Type> d_typePtr;

  public:
    Unique() = default;
    Unique(Unique const &other);
    Unique(Unique &&tmp);
    Unique(Type val);
    Unique(Type *valPtr);

    void operator=(Unique const &other);
    void operator=(Unique &&tmp);

    Type const &get() const;
    Type &get();

};

template<typename Type>
inline Unique<Type>::Unique(Unique const &other)
  :
  d_typePtr(std::make_unique<Type>(*other.d_typePtr))
{}

template<typename Type>
inline Unique<Type>::Unique(Unique &&tmp)
  :
  d_typePtr(std::move(tmp))
{}

template<typename Type>
inline Unique<Type>::Unique(Type val)
  :
  d_typePtr(std::make_unique<Type>(val))
{}

template<typename Type>
inline Unique<Type>::Unique(Type *valPtr)
  :
  d_typePtr(valPtr)
{}

template<typename Type>
void Unique<Type>::operator=(const Unique<Type> &other)
{
  d_typePtr = std::make_unique<Type>(*other.d_typePtr);
}

template<typename Type>
inline void Unique<Type>::operator=(Unique<Type> &&tmp)
{
  d_typePtr = std::move(tmp.d_typePtr);
}

template<typename Type>
Type const &Unique<Type>::get() const
{
  return *d_typePtr;
}
template<typename Type>
Type &Unique<Type>::get()
{
  return *d_typePtr;
}

#endif //SET1_UNIQUE_H