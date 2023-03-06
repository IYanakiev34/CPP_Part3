#ifndef PLUS_H
#define PLUS_H

template <class Type>
struct Plus
{
    Type operator()(Type const &left, Type const &right);
};

template <class Type>
inline Type Plus<Type>::operator()(Type const &left, Type const &right)
{
    return left + right;
}

#endif