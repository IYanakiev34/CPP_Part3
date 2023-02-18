#ifndef SIMPLE_H
#define SIMPLE_H

#include <iostream>

template <typename Type>
class Simple
{
    Type d_value = Type{};

public:
    Simple() = default;
    Simple(Type const &value);

    Type &get();
};

template <typename Type>
class Simple <Type*>
{
    Type d_value = Type{};
public:
    Simple() = default;
    Simple(Type *ptr);
    Simple(Type val);
    Type &get();
};

template<typename Type>
Type &Simple<Type>::get()
{
    return d_value;
}

template<typename Type>
Simple<Type>::Simple(Type const &value)
    : d_value(value)
{
}

template<typename Type>
Simple<Type *>::Simple(Type *ptr)
    : d_value(*ptr)
{
}

template<typename Type>
Simple<Type *>::Simple(Type val)
    : d_value(val)
{
}

template<typename Type>
Type &Simple<Type *>::get()
{
    return d_value;
}

#endif