#ifndef BASE_INCLUDED_H
#define BASE_INCLUDED_H

#include <iostream>

template <typename Derived, typename Ret, typename... Args>
class Base
{
public:
    using FuncPtr = Ret (Derived::*)(Args...);

    Ret nc(Args... args) { return static_cast<Derived *>(this)->nc_impl(args...); }
};

class Derived : public Base<Derived, int, double>
{
public:
    int nc_impl(double d) { return static_cast<int>(d); }
};

#endif