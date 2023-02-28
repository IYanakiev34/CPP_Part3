template <typename T>
inline T &Unique<T>::get()
{
  return *d_data;
}
