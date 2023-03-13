#ifndef SET5_NORMALITERATOR_H
#define SET5_NORMALITERATOR_H

#define ItTemplate template <typename IData, \
    template <typename> class Container>

#define FreeFunctionTemplate template < \
  template <typename, template <typename> class> class Iter, \
  typename FData, \
  template <typename> class FContainer \
>                                       \
  requires NormalIterator<Iter, FData, FContainer>

#include <concepts>

                                // Forward declare iterator to use in concept
ItTemplate
struct Iterator;

                                // This concept ensures that an iterator passed
                                // to it is exactly the Iterator type. Used to
                                // disambiguate which iterator the free
                                // operations refer to.
template <
  template <typename, template <typename> class> class Iter,
  typename Data,
  template <typename> class Container
>
concept NormalIterator =
std::same_as<Iter<Data, Container>, Iterator<Data, Container>>;

#endif //SET5_NORMALITERATOR_H
