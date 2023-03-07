#ifndef SET4_ITERATOR_H
#define SET4_ITERATOR_H

#include <vector>
#include <iterator>

template <typename Data, template <typename> class Container>
struct Iterator
{
  using iterator_category = std::random_access_iterator_tag;
  using difference_type   = std::ptrdiff_t;
  using value_type        = Data;
  using pointer           = value_type const *;
  using reference         = value_type const &;

  private:
    typename Container<Data *>::iterator d_current;
  public:
    Iterator(typename Container<Data *>::iterator const &current);

                      // TODO: Make free
    auto operator<=>(Iterator const &rhs) const;
    bool operator==(Iterator const &rhs) const;
    int operator-(Iterator const &rhs) const;
    int operator+(Iterator const &rhs) const;

    Iterator operator+(int step) const;
    Iterator operator-(int step) const;
    Iterator &operator+=(int step);
    Iterator &operator-=(int step);


    Iterator &operator--();
    Iterator operator--(int);
    Iterator &operator++();
    Iterator operator++(int);


    Data &operator*();
    Data *operator->();

};

template <typename Data, template <typename> class Container>
Iterator<Data, Container>::Iterator(
  typename Container<Data *>::iterator const &current
)
  : d_current(current)
{}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> Iterator<Data, Container>::operator+(int step) const
{
  Iterator ret{*this};
  ret.d_current += step;
  return ret;
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> Iterator<Data, Container>::operator-(int step) const
{
  Iterator ret{*this};
  ret.d_current -= step;
  return ret;
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> &Iterator<Data, Container>::operator+=(int step)
{
  d_current += step;
  return *this;
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> &Iterator<Data, Container>::operator-=(int step)
{
  d_current -= step;
  return *this;
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> Iterator<Data, Container>::operator++(int)
{
  return iterator(d_current++);
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> Iterator<Data, Container>::operator--(int)
{
  return iterator(d_current--);
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> &Iterator<Data, Container>::operator++()
{
  ++d_current;
  return *this;
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> &Iterator<Data, Container>::operator--()
{
  --d_current;
  return *this;
}

template <typename Data, template <typename> class Container>
Data &Iterator<Data, Container>::operator*()
{
  return **d_current;
}

template <typename Data, template <typename> class Container>
Data *Iterator<Data, Container>::operator->()
{
  return *d_current;
}

#endif //SET4_ITERATOR_H
