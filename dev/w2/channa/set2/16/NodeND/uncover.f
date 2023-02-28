template<size_t N>
void NodeND<N>::uncover(size_t dim)
{
  d_dims[dim].uncover();
}
