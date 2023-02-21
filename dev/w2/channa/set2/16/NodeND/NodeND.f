template <size_t N>
NodeND<N>::NodeND()
{
  for (size_t idx = 0; idx != N; ++idx)
    d_dims[idx] = new Node1D(this);
}
