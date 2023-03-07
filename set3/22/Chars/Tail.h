#ifndef SET3_TAIL_H
#define SET3_TAIL_H

#include "Chars.h"

                            // Template class to get the tail of a CharsT
                            // template.
                            // e.g: Tail<Char<'a','b','c'>>::tail
                            // -> Char<'b','c'>
template <typename CharsT>
struct Tail
{};

template<char first, char ...rest>
struct Tail<Chars<first, rest...>>
{
  using tail = Chars<rest...>;
};

#endif //SET3_TAIL_H
