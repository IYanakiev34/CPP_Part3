#ifndef INC_9_UNIQUE_H
#define INC_9_UNIQUE_H

#include <memory>

template <typename Type>
class Unique
{
    std::unique_ptr<Type> d_ptr;
    static size_t s_count;
    static size_t s_actual;
public:
    Unique();
    explicit Unique(Type value);
    explicit Unique(Type *ptr);
    Unique(Unique<Type> const &other);
    Unique(Unique<Type> &&other) noexcept;
    Unique &operator=(Unique const &other);
    Unique &operator=(Unique &&other) noexcept;
    Type &get();
    Type const &get() const;
    [[nodiscard]] static size_t count();
    [[nodiscard]] static size_t actual();
};

template<typename Type>
size_t Unique<Type>::s_count = 0;

template<typename Type>
size_t Unique<Type>::s_actual = 0;

template<typename Type>
Unique<Type>::Unique(Type value)
        : d_ptr(std::make_unique<Type>(std::move(value)))
{
    s_actual++;
    s_count++;
}

template<typename Type>
Unique<Type>::Unique(Type *ptr)
        : d_ptr(ptr)
{
    s_actual++;
    s_count++;
}

template<typename Type>
Unique<Type>::Unique(const Unique<Type> &other)
        : d_ptr(other.d_ptr ? new Type{*other.d_ptr} : nullptr)
{
    s_actual++;
    s_count++;
}

template<typename Type>
Unique<Type> &Unique<Type>::operator=(const Unique &other)
{
    s_actual++;
    s_count++;
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

template<typename Type>
inline size_t Unique<Type>::count()
{
    return s_count;
}

template<typename Type>
inline size_t Unique<Type>::actual()
{
    return s_actual;
}

template<typename Type>
Unique<Type>::Unique()
{
    s_actual++;
    s_count++;
}

template<typename Type>
Unique<Type>::Unique(Unique<Type> &&other) noexcept
{
    s_count++;
}

template<typename Type>
Unique<Type> &Unique<Type>::operator=(Unique &&other) noexcept
{
    s_count++;
    if (this != &other)
    {
        d_ptr = std::move(other.d_ptr);
        other.d_ptr = nullptr;
    }
    return *this;
}

#endif //INC_9_UNIQUE_H
