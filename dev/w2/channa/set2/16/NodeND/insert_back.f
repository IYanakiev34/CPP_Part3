template<size_t N>
void NodeND<N>::insert_back(NodeND &other, size_t dim)
{
  d_dims[dim].insert_back(&other.d_dims[dim]);
}
