#include "Node1D.ih"

void Node1D::uncover()
{
  d_prev->d_next = this;
  d_next->d_prev = this;
}
