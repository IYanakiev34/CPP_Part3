template<size_t N>
void NodeND<N>::cover(size_t dim) const
{
  d_dims[dim].cover();
}
