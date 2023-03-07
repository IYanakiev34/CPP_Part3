template <typename T>
Unique<T> &Unique<T>::operator=(Unique<T> const &other)
{
  d_data.reset(other.d_data ? std::make_unique<T>(*other.d_data) : nullptr);
}
