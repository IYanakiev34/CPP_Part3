#ifndef INSERTABLE_H
#define INSERTABLE_H

#include <ostream>

// Policy class for inserting values from a container into ostream
template<template<typename, typename> class Policy, typename Value>
struct Insertable : public Policy<Value, std::allocator<Value>>
{
// idk if this is okay but saves me some effort
using Container = Policy<Value, std::allocator<Value>>;

Insertable() = default;
Insertable(Insertable const &other) = default;
Insertable(Insertable &&other) noexcept = default;
explicit Insertable(Value const &value);
explicit Insertable(Container const &policy);
};

template<template<typename, typename> class Policy, typename Value>
Insertable<Policy, Value>::Insertable(Value const &value)
{
    this->push_back(value);
}

template<template<typename, typename> class Policy, typename Value>
Insertable<Policy, Value>::Insertable(Container const &policy)
        : Container(policy)
{
}

// insertion operator for Insertable
template<template<typename, typename> class Policy, typename Value>
std::ostream &operator<<(std::ostream &os,
                         Insertable<Policy, Value> const &insertable)
{
    for (auto const &value : insertable)
        os << value << "\n";
    return os;
}

#endif
