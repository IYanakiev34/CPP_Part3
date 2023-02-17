//JB: ?
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

/* JB:
   Even if we only asked to call the function, the decltype(auto) is very
   nice :-)
   But there still is a problem: this forwarder only works if 'fun' can be
   copied. So not if it's an object of a class that has no copy constructor.
 */
