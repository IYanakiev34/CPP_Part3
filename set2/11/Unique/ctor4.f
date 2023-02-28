template <typename T>
Unique<T>::Unique(Unique<T> const &other)
    : d_data(other.d_data ? std::make_unique<T>(*other.d_data) : nullptr)
{
  ++s_count;
  ++s_actual;
}
