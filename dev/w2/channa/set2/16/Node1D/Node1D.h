#ifndef SET2_NODE1D_H
#define SET2_NODE1D_H

#include <cstddef>

class Node1D
{
  Node1D *d_owner = 0;

  Node1D *d_prev = 0;
  Node1D *d_next = 0;

  public:
    Node1D() = default;
    Node1D(Node1D * owner);

    Node1D *owner();
    Node1D *prev();
    Node1D *next();

    void insert_front(Node1D * const other);
    void insert_back(Node1D * const other);

    void cover();
    void uncover();
};

inline Node1D *Node1D::owner()
{
  return d_owner;
}

inline Node1D *Node1D::prev()
{
  return d_prev;
}

inline Node1D *Node1D::next()
{
  return d_next;
}

#endif //SET2_NODE1D_H
