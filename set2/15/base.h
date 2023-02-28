#ifndef BASE_INCLUDED_H
#define BASE_INCLUDED_H

#include <iostream>

template <typename Derived>
class Base
{
public:
    template <typename Ret, typename... Args>
    Ret nc(Args... args) { return static_cast<Derived *>(this)->nc_impl(args...); }
};

#endif