template <typename T>
Unique<T>::Unique(T type)
    : d_data(new T{type})
{
  ++s_count;
  ++s_actual;
}
