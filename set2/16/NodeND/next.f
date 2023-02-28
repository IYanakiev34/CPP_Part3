template<size_t N>
NodeND<N> *NodeND<N>::next(size_t dim) const
{
  return static_cast<NodeND *>(d_dims[dim].next()->owner());
}