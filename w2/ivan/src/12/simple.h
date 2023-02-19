#ifndef SIMPLE_INCLUDED_H
#define SIMPLE_INCLUDED_H

#include <iostream>

template <typename Type>
class Simple
{
    Type d_data = Type{};

public:
    Simple()
    {
        std::cout << "Standard default constructor\n";
    }

    Simple(Type const &other)
        : d_data(other)
    {
    }

    Type &get()
    {
        return d_data;
    }
};

template <typename Type>
class Simple<Type *>
{
    Type *d_data;

public:
    Simple()
        : d_data(nullptr)
    {
        std::cout << "Specialed Type ptr constructor\n";
    }

    Simple(Type *ptr)
        : d_data(ptr)
    {
        std::cout << "Specialized Type ptr constructor called with value of type ptr\n";
    }

    Type &get()
    {
        return *d_data;
    }
};

#endif