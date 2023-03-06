#ifndef SET4_ITERATOR_H
#define SET4_ITERATOR_H

#include <vector>

template <typename Data, template <typename> class Container>
class Iterator
{
  typename Container<Data *>::iterator &d_current;
  public:
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Data;
    using point = value_type *;
    using reference = value_type &;

    Iterator(typename Container<Data *>::iterator const &current);

    Iterator operator+(size_t step);
    Iterator operator+=(size_t step);
    Iterator operator-(size_t step);
    Iterator operator-=(size_t step);

    Iterator operator++();
    Iterator operator--();

    Data &operator*();
    Data *operator->();
};

template <typename Data, template <typename> class Container>
Iterator<Data, Container>::Iterator(
  typename Container<Data *>::iterator const &current
)
  : d_current(current)
{
}

template <typename Data, template <typename> class Container>
bool operator==(
  Iterator<Data, Container> const &lhs, Iterator<Data, Container> const &rhs
)
{
}

template <typename Data, template <typename> class Container>
auto operator<=>(
  Iterator<Data, Container> const &lhs, Iterator<Data, Container> const &rhs
)
{
}

template <typename Data, template <typename> class Container>
bool operator-(
  Iterator<Data, Container> const &lhs, Iterator<Data, Container> const &rhs
)
{
}

#endif //SET4_ITERATOR_H
