#ifndef PLUS_H
#define PLUS_H

template <typename Type>
struct Plus
{
    Type operator()(Type const &lhs, Type const &rhs)
};

template <typename Type>
Type Plus<Type>::operator()(Type const &lhs, Type const &rhs)
{
    return lhs + rhs;
}

#endif