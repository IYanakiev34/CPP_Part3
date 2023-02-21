#include "Node1D.ih"

void Node1D::insert_front(Node1D *const other)
{
  if (!d_next)
    d_next = other;
  else
  {
    Node1D * const prev_front = d_next;
    other->d_next = prev_front;
    prev_front->d_prev = other;
    d_next = other;
    other->d_prev = this;
  }
}
