template <typename T>
Unique<T>::Unique()
  : d_data(nullptr)
{
  ++s_count;
  ++s_actual;
}
