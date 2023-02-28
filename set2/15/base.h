#ifndef BASE_INCLUDED_H
#define BASE_INCLUDED_H

template <typename Derived>
class Base
{
public:
    template <typename Ret, typename... Args>
    Ret nc(Args... args);
};

template <typename Derived>
template <typename Ret, typename... Args>
Ret Base<Derived>::nc(Args ...args)
{
  return static_cast<Derived *>(this)->nc_impl(args...);
}

#endif