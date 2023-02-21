#include "Node1D.ih"

void Node1D::cover()
{
  d_prev->d_next = d_next;
  d_next->d_prev = d_prev;
}