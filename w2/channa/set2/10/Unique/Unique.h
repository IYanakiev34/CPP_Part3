#ifndef SET1_UNIQUE_H
#define SET1_UNIQUE_H

#include <memory>

template <typename Type>
class Unique
{
  static size_t s_count;
  static size_t s_actual;

  std::unique_ptr<Type> d_typePtr;

  public:
    Unique();
    Unique(Unique const &other);
    Unique(Unique &&tmp);
    explicit Unique(Type val);
    explicit Unique(Type *valPtr);
    ~Unique();

    Unique<Type> &operator=(Unique const &other);
    Unique<Type> &operator=(Unique &&tmp);

    Type const &get() const;
    Type &get();

    static size_t count();
    static size_t actual();

  private:
    void incrementConstructionCounts();
};

template <typename Type>
inline Unique<Type>::Unique()
{
  incrementConstructionCounts();
}

template <typename Type>
inline Unique<Type>::Unique(Unique const &other)
  :
  d_typePtr(std::make_unique<Type>(*other.d_typePtr))
{
  incrementConstructionCounts();
}

template <typename Type>
inline Unique<Type>::Unique(Unique &&tmp)
  :
  d_typePtr(std::move(tmp))
{
                        // Technically a new object, so counts as construction
                        // s_actual will get decremented when anonymous obj.
                        // goes out of scope
  incrementConstructionCounts();
}

template <typename Type>
inline Unique<Type>::Unique(Type val)
  :
  d_typePtr(std::make_unique<Type>(val))
{
    incrementConstructionCounts();
}

template <typename Type>
inline Unique<Type>::Unique(Type *valPtr)
  :
  d_typePtr(valPtr)
{
    incrementConstructionCounts();
}

template <typename Type>
Unique<Type>::~Unique() {
  --s_actual;
}

template <typename Type>
inline Unique<Type> &Unique<Type>::operator=(const Unique<Type> &other)
{
  d_typePtr = std::make_unique<Type>(*other.d_typePtr);
  return *this;
}

template <typename Type>
inline Unique<Type> &Unique<Type>::operator=(Unique<Type> &&tmp)
{
  d_typePtr = std::move(tmp.d_typePtr);
  return *this;
}

template <typename Type>
Type const &Unique<Type>::get() const
{
  return *d_typePtr;
}
template <typename Type>
Type &Unique<Type>::get()
{
  return *d_typePtr;
}

template <typename Type>
size_t Unique<Type>::count()
{
  return s_count;
}

template <typename Type>
size_t Unique<Type>::actual()
{
  return s_actual;
}

template <typename Type>
void Unique<Type>::incrementConstructionCounts()
{
  ++s_count;
  ++s_actual;
}

template<typename Type>
size_t Unique<Type>::s_count = 0;

template<typename Type>
size_t Unique<Type>::s_actual = 0;

#endif //SET1_UNIQUE_H