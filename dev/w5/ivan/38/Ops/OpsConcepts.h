#ifndef OPERATIONS_CONCEPTS_H
#define OPERATIONS_CONCEPTS_H

#include "../Math/MathConcept.h"
#include <iostream>

template <typename Lhs, typename Rhs>
    requires BasicMath<Lhs, Rhs>
struct Add
{
    static void operation(Lhs lhs, Rhs rhs)
    {
        std::cout << (lhs + rhs) << ' ';
    }
};

template <typename Lhs, typename Rhs>
    requires BasicMath<Lhs, Rhs>
struct Sub
{
    static void operation(Lhs lhs, Rhs rhs)
    {
        std::cout << (lhs - rhs) << ' ';
    }
};

template <typename Lhs, typename Rhs>
    requires BasicMath<Lhs, Rhs>
struct Mul
{
    static void operation(Lhs lhs, Rhs rhs)
    {
        std::cout << (lhs * rhs) << ' ';
    }
};

template <typename Lhs, typename Rhs>
    requires BasicMath<Lhs, Rhs>
struct Div
{
    static void operation(Lhs lhs, Rhs rhs)
    {
        std::cout << (lhs / rhs) << ' ';
    }
};

#define Operation template <typename, typename> \
class

template <Operation Op, typename... Args>
void math();

// Base case
template <Operation Op, typename First>
void math(First first)
{
    std::cout << '\n';
}

template <Operation Op, typename First, typename Second, typename... Args>
void math(First first, Second second, Args... args)
{
    Op<First, Second>::operation(first, second);
    math<Operation>(first, rest...);
}

#endif