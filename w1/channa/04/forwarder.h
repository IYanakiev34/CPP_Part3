#ifndef SET1_FORWARDER_H
#define SET1_FORWARDER_H

#include <utility>

template <typename Function, typename ...Args>
auto forwarder(Function fun, Args &&...args)
  -> decltype(fun(std::forward<Args>(args)...))
{
  return fun(std::forward<Args>(args)...);
}
#endif //SET1_FORWARDER_H
