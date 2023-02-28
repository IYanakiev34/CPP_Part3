template <typename T>
Unique<T>::~Unique()
{
  --s_actual;
}
