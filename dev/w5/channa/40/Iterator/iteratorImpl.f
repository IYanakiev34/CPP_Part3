
#include "Iterator.h"

ItTemplate
inline typename ItType::reference ItType::operator*() const
{
  return **d_current;
}

ItTemplate
inline typename ItType::pointer ItType::operator->() const
{
  return *d_current;
}

ItTemplate
ItType &ItType::operator-=(Iterator::difference_type diff)
{
  d_current -= diff;
  return *this;
}

ItTemplate
ItType &Iterator<IData, Container>::operator+=(Iterator::difference_type diff)
{
  d_current += diff;
  return *this;
}

ItTemplate
inline ItType ItType::operator-(Iterator::difference_type diff) const
{
  return Iterator(d_current - diff);
}

ItTemplate
inline ItType ItType::operator+(Iterator::difference_type diff) const
{
  return Iterator(d_current + diff);
}

ItTemplate
  ItType ItType::operator--(int)
{
  Iterator temp(*this);
  --d_current;
  return temp;
}

ItTemplate
  ItType &ItType::operator--()
{
  --d_current;
  return *this;
}

ItTemplate
  ItType ItType::operator++(int)
{
  Iterator temp(*this);
  ++d_current;
  return temp;
}

ItTemplate
  ItType &ItType::operator++()
{
  ++d_current;
  return *this;
}

ItTemplate
ItType::Iterator(typename Container<IData *>::iterator const &current)
: d_current(current)
  {}

FreeFunctionTemplate
bool operator==(
  Iter<FData, FContainer> const &lhs,
  Iter<FData, FContainer> const &rhs
)
{
  return lhs.d_current == rhs.d_current;
}

FreeFunctionTemplate
auto operator<=>(
  Iter<FData, FContainer> const &lhs,
  Iter<FData, FContainer> const &rhs)
{
  return lhs.d_current <=> rhs.d_current;
}

FreeFunctionTemplate
std::ptrdiff_t operator-(
  Iter<FData, FContainer> const &lhs,
  Iter<FData, FContainer> const &rhs
)
{
  return lhs.d_current - rhs.d_current;
}
