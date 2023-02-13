#ifndef SET1_FORWARDER_H
#define SET1_FORWARDER_H

#include <utility>

                      // forwarder forwards args to fun
template <typename Function, typename ...Args>
decltype(auto) forwarder(Function fun, Args &&...args)
{
  return fun(std::forward<Args>(args)...);
}
#endif //SET1_FORWARDER_H
