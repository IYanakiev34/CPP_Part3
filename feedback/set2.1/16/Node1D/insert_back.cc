#include "Node1D.ih"

void Node1D::insert_back(Node1D *const other)
{
  if (!d_prev)
    d_prev = other;
  else
    d_prev->insert_front(other);
}
