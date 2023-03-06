#ifndef SET3_INSERTABLE_H
#define SET3_INSERTABLE_H

#include <ostream>
#include <iterator>

template <template <typename> class Container, typename Data>
struct Insertable : Container<Data>
{
                                // Defined in ctors.f
  Insertable();
  Insertable(Insertable<Container, Data> const &other);
  Insertable(Insertable<Container, Data> &&tmp);
  Insertable(Container<Data> const &cont);
  Insertable(Container<Data> &&tmpCont);
  Insertable(Data const &elem);
  Insertable(Data &&tmpElem);
};

template <template <typename> class Container, typename Data>
std::ostream &operator<<(
  std::ostream &out, Insertable<Container, Data> insertable
);

#include "ctors.f"
#include "insertion.f"

#endif //SET3_INSERTABLE_H
