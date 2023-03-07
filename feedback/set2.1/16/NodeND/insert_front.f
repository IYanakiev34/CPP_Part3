template<size_t N>
void NodeND<N>::insert_front(NodeND &other, size_t dim)
{
  d_dims[dim].insert_front(&other.d_dims[dim]);
}
