template <typename T>
inline T const &Unique<T>::get() const
{
  return *d_data;
}
