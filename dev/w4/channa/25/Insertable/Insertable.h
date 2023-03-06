#ifndef SET3_INSERTABLE_H
#define SET3_INSERTABLE_H

#include <ostream>

template <template <typename> class Container, typename Data>
struct Insertable : Container<Data>
{
  Insertable();
  Insertable(Insertable const &other);
  Insertable(Insertable &&tmp);

  Insertable(Container<Data> const &cont);
  Insertable(Container<Data> &&tmpCont);

  Insertable(Data const &elem);
  Insertable(Data &&tmpElem);
};

template <template <typename> class Container, typename Data>
std::ostream &operator<<(
  std::ostream &out, Insertable<Container, Data> insertable
);

#endif //SET3_INSERTABLE_H
