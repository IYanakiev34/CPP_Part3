template <typename Data>
inline typename Storage<Data>::iterator &Storage<Data>::iterator::operator++()
{
  ++d_current;
  return *this;
}

template <typename Data>
inline typename Storage<Data>::iterator Storage<Data>::iterator::operator++(int)
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
inline typename Storage<Data>::iterator Storage<Data>::iterator::operator--(int)
{
  return iterator(d_current--);
}

template <typename Data>
inline typename Storage<Data>::iterator Storage<Data>::iterator::operator-(
  int step) const
{
  Storage<Data>::iterator ret{ *this };
  ret.d_current -= step;                  // avoids ambiguity
  return ret;
}

template <typename Data>
inline Data &Storage<Data>::iterator::operator*()
{
  return **d_current;
}

template <typename Data>
inline Data *Storage<Data>::iterator::operator->()
{
  return &**d_current;
}

template <typename Data>
inline typename Storage<Data>::iterator &Storage<Data>::iterator::operator+=(int step)
{
  d_current += step;
  return *this;
}

template <typename Data>
inline typename Storage<Data>::iterator &Storage<Data>::iterator::operator-=(int step)
{
  d_current -= step;
  return *this;
}
