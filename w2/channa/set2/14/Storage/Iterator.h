#ifndef SET2_ITERATOR_H
#define SET2_ITERATOR_H

#include "Storage.h"

template <typename Data>
class Storage<Data>::iterator
{
  friend Storage<Data>;

  typename std::vector<Data *>::iterator d_current;

  friend bool operator==(iterator const &lhs, iterator const &rhs);
  friend auto operator<=>(iterator const &lhs, iterator const &rhs);
  friend int operator-(iterator const &lhs, iterator const &rhs);
  friend iterator operator-(iterator const &lhs, iterator const &rhs);
  friend iterator operator+(iterator const &lhs, iterator const &rhs);

  friend int operator+(iterator const &lhs, int stepSize);
  friend int operator-(iterator const &lhs, int stepSize);

  public:
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Data;
    using point = value_type *;
    using reference = value_type &;

    iterator &operator++();
    iterator &operator++(int);
    iterator &operator--();
    iterator &operator--(int);
    iterator &operator=(iterator const &other) = default;

    Data &operator*() const;

    Data *operator->() const;

    iterator &operator+=(int step);
    iterator &operator-=(int step);

  private:
    iterator(typename std::vector<Data *>::iterator iterator);
};

template <typename Data>
inline Storage<Data>::iterator::iterator(
  typename std::vector<Data *>::iterator iterator
)
  :
  d_current(iterator)
{}

template <typename Data>
inline typename Storage<Data>::iterator &Storage<Data>::iterator::operator++()
{
  ++d_current;
  return *this;
}

template <typename Data>
inline typename Storage<Data>::iterator &Storage<Data>::iterator::operator++(int)
{
  return iterator(d_current++);
}

template <typename Data>
inline typename Storage<Data>::iterator &Storage<Data>::iterator::operator--()
{
  --d_current;
  return *this;
}

template <typename Data>
inline typename Storage<Data>::iterator &Storage<Data>::iterator::operator--(int)
{
  return iterator(d_current--);
}

template <typename Data>
inline bool operator==(
  typename Storage<Data>::iterator const &lhs,
  typename Storage<Data>::iterator const &rhs
)
{
  return lhs.d_current == rhs.d_current;
}

template <typename Data>
inline auto operator<=>(
  typename Storage<Data>::iterator const &lhs,
  typename Storage<Data>::iterator const &rhs
)
{
  return lhs.d_current <=> rhs.d_current;
}

template <typename Data>
inline int operator-(
  typename Storage<Data>::iterator const &lhs,
  typename Storage<Data>::iterator const &rhs
)
{
  return lhs.d_current - rhs.d_current;
}

template <typename Data>
inline typename Storage<Data>::iterator operator-(
  typename Storage<Data>::iterator const &lhs,
  typename Storage<Data>::iterator const &rhs
)
{
  return lhs.d_current - rhs.d_current;
}

template <typename Data>
inline typename Storage<Data>::iterator operator+(
  typename Storage<Data>::iterator const &lhs,
  typename Storage<Data>::iterator const &rhs
)
{
  return lhs.d_current + rhs.d_current;
}

template <typename Data>
inline int operator+(
  typename Storage<Data>::iterator const &lhs,
  int stepSize
)
{
  typename Storage<Data>::iterator ret{lhs};
  ret.d_current += stepSize;
  return ret;
}

template <typename Data>
inline int operator-(
  typename Storage<Data>::iterator const &lhs,
  int stepSize
)
{
  typename Storage<Data>::iterator ret{lhs};
  ret.d_current -= stepSize;
  return ret;
}

template <typename Data>
inline Data &Storage<Data>::iterator::operator*() const
{
  return **d_current;
}

template <typename Data>
inline Data *Storage<Data>::iterator::operator->() const
{
  return *d_current;
}

template <typename Data>
inline typename Storage<Data>::iterator &Storage<Data>::iterator::operator+=(
  int step
)
{
  d_current += step;
  return *this;
}

template <typename Data>
inline typename Storage<Data>::iterator &Storage<Data>::iterator::operator-=(
  int step
)
{
  d_current -= step;
  return *this;
}

#endif //SET2_ITERATOR_H
