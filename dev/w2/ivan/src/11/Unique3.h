#ifndef UNIQUE3_INCLUDED_H
#define UNIQUE3_INCLUDED_H

#include "Counter.h"
#include <memory>

template <typename T>
class Unique
{
    std::unique_ptr<T> d_data;
    Counter d_counter;

public:
    static std::size_t s_count;
    static std::size_t s_actual;
    Unique()
        : d_data(nullptr)
    {
        ++s_count;
        ++s_actual;
    }

    ~Unique()
    {
        --s_actual;
    }

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
    : d_data(std::make_unique<T>(std::move(type)))
{
    ++s_count;
    ++s_actual;
}

template <typename T>
Unique<T>::Unique(T *ptr)
    : d_data(ptr)
{
    ++s_count;
    ++s_actual;
}

template <typename T>
Unique<T>::Unique(Unique<T> const &other)
    : d_data(other.d_data ? std::make_unique<T>(*other.d_data) : nullptr)
{
    ++s_count;
    ++s_actual;
}

template <typename T>
Unique<T> &Unique<T>::operator=(Unique<T> const &other)
{
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

template <typename T>
std::size_t Unique<T>::s_count = 0;

template <typename T>
std::size_t Unique<T>::s_actual = 0;

#endif