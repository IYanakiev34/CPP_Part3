#ifndef SET3_INSERTABLE_H
#define SET3_INSERTABLE_H

#include <ostream>
                                // Container is meant to be a template class
                                // like vector, deque, list, etc.

                                // Data is the data that would be contained
                                // inside container. Assumes that Data is
                                // insertable into a stream.

                                // Insertable is designed such that if inserted
                                // into an ostream, a space seaparated list
                                // of the data elements are put into the ostream
template <template <typename> class Container, typename Data>
struct Insertable : Container<Data>
{
  Insertable();
  Insertable(Insertable const &other);
  Insertable(Insertable &&tmp);

                                      // Construct insertable based of
                                      // existing containers
  Insertable(Container<Data> const &cont);
  Insertable(Container<Data> &&tmpCont);

                                    // Create a container with a single element
  Insertable(Data const &elem);
  Insertable(Data &&tmpElem);
};

                                    // Output the elements held in insertable
                                    // as a space separated list to out.
template <template <typename> class Container, typename Data>
std::ostream &operator<<(
  std::ostream &out, Insertable<Container, Data> insertable
);

#endif //SET3_INSERTABLE_H