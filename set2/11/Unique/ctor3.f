template <typename T>
Unique<T>::Unique(T *ptr)
    : d_data(ptr)
{
  ++s_count;
  ++s_actual;
}
