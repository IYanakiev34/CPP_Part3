template <size_t N>
NodeND<N>::~NodeND()
{
  for (size_t idx = 0; idx != N; ++idx)
    delete d_dims[idx];
}
