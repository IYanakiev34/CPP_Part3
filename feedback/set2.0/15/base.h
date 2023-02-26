//JB: 0
#ifndef BASE_INCLUDED_H
#define BASE_INCLUDED_H

#include <iostream> //JB: BH: overkill (or should be).

// JB: Having Args in the class template makes it TC IMO.
template <typename Derived, typename Ret, typename... Args>
class Base
{
public:
    using FuncPtr = Ret (Derived::*)(Args...);
    // Same for const funcptr

    //JB: ICI
    Ret nc(Args... args) { return static_cast<Derived *>(this)->nc_impl(args...); }
};

//JB: Just an example, I suppose?
//JB: Good that you test, but move it elsewhere.
//JB: It also shows that with those class parameters, use becomes complex.
class Derived : public Base<Derived, int, double>
{
public:
    int nc_impl(double d) { return static_cast<int>(d); }
};

#endif
