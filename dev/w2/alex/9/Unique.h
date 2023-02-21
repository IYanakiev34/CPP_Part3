#ifndef INC_9_UNIQUE_H
#define INC_9_UNIQUE_H

#include <memory>

template <typename Type>
class Unique
{
    std::unique_ptr<Type> d_ptr;
public:
    Unique() = default;
    explicit Unique(Type value);
    explicit Unique(Type *ptr);
    Unique(Unique<Type> const &other);
    Unique(Unique<Type> &&other) noexcept = default;
    Unique &operator=(Unique const &other);
    Unique &operator=(Unique &&other) noexcept = default;
    Type &get();
    Type const &get() const;
};

template<typename Type>
Unique<Type>::Unique(Type value)
        : d_ptr(std::make_unique<Type>(std::move(value)))
{
}

template<typename Type>
Unique<Type>::Unique(Type *ptr)
        : d_ptr(ptr)
{
}

template<typename Type>
Unique<Type>::Unique(const Unique<Type> &other)
        : d_ptr(other.d_ptr ? new Type{*other.d_ptr} : nullptr)
{
}

template<typename Type>
Unique<Type> &Unique<Type>::operator=(const Unique &other)
{
    Type *ptr = other.d_ptr ? new Type{*other.d_ptr} : nullptr;
    d_ptr.reset(ptr);
    return *this;
}

template <typename Type>
inline Type &Unique<Type>::get()
{
    return *d_ptr;
}

template <typename Type>
inline Type const &Unique<Type>::get() const
{
    return *d_ptr;
}


#endif //INC_9_UNIQUE_H
