// JB: ?
#ifndef UNIQUE_INCLUDED_H
#define UNIQUE_INCLUDED_H

#include <memory>

template <typename T>
class Unique
{
    std::unique_ptr<T> d_data;

public:
    Unique() = default; // JB:
    Unique(T type);
    Unique(T *tPtr);
    Unique(Unique &&tmp) = default;
    Unique(Unique const &other);

    Unique &operator=(Unique const &other);
    Unique &operator=(Unique &&tmp) noexcept = default;

    T const &get() const;
    T &get();
};

template <typename T>
Unique<T>::Unique(T type)
    : d_data(new T(type))
{
}

template <typename T>
Unique<T>::Unique(T *ptr)
    : d_data(ptr)
{
}

template <typename T>
Unique<T>::Unique(Unique<T> const &other)
    : d_data(other.d_data ? std::make_unique<T>(*other.d_data) : nullptr)
{
}

template <typename T>
Unique<T> &Unique<T>::operator=(Unique<T> const &other)
{
    // JB: Fair enough...
    d_data.reset(other.d_data ? std::make_unique<T>(*other.d_data) : nullptr);
}

template <typename T>
inline T const &Unique<T>::get() const
{
    return *d_data;
}

template <typename T>
inline T &Unique<T>::get()
{
    return *d_data;
}

#endif
