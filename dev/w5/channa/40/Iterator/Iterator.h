#ifndef SET4_ITERATOR_H
#define SET4_ITERATOR_H

#define ItTemplate template <typename IData, \
    template <typename> class Container>

#define FreeFunctionTemplate template < \
  template <typename, template <typename> class> class Iter, \
  typename FData, \
  template <typename> class FContainer \
>                                       \
  requires NormalIterator<Iter, FData, FContainer>

#define ItType Iterator<IData, Container>

#include "NormalIterator.h"

#include <iterator>

ItTemplate
struct Iterator
{
  private:
    typename Container<IData *>::iterator d_current;
  public:
                                          // Using declarations needed for
                                          // random access iterators
    using difference_type = std::ptrdiff_t;
    using value_type = IData;
    using pointer = IData *;
    using reference = IData &;
    using iterator_category = std::random_access_iterator_tag;

    Iterator() = default;
    Iterator(typename Container<IData *>::iterator const &current);

                                    // Free operators. Note how the concept
                                    // defines that this free function _must_
                                    // have the Iter passed to it be the same
                                    // as Iterator.
    FreeFunctionTemplate
    friend bool operator==(
      Iter<FData, FContainer> const &lhs,
      Iter<FData, FContainer> const &rhs
    );

    FreeFunctionTemplate
    friend auto operator<=>(
      Iter<FData, FContainer> const &lhs,
      Iter<FData, FContainer> const &rhs
    );

    FreeFunctionTemplate
    friend std::ptrdiff_t operator-(
      Iter<FData, FContainer> const &lhs,
      Iter<FData, FContainer> const &rhs
    );

                                    // Standard operations needed for Rand.
                                    // access iterators
    Iterator &operator++();
    Iterator operator++(int);
    Iterator &operator--();
    Iterator operator--(int);

    Iterator operator+(difference_type diff) const;
    Iterator operator-(difference_type diff) const;

    Iterator &operator+=(difference_type diff);
    Iterator &operator-=(difference_type diff);

    reference operator*() const;
    pointer operator->() const;
};

#include "iteratorImpl.f"

#undef FreeFunctionTemplate
#undef ItTemplate
#undef ItType
#endif