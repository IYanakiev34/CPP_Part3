#ifndef SET2_NODE1D_H
#define SET2_NODE1D_H

#include "../OwnerNode/OwnerNode.h"

#include <cstddef>

class Node1D
{
                            // An 1D node in this data structure is always
                            // owned by NodeND node. The NodeND is an OwnerNode
  OwnerNode *d_owner = nullptr;

  Node1D *d_prev = nullptr;
  Node1D *d_next = nullptr;

  public:
    Node1D() = default;
    Node1D(OwnerNode * owner);

    OwnerNode *owner() const;
    Node1D *prev() const;
    Node1D *next() const;

    void insert_front(Node1D * const other);
    void insert_back(Node1D * const other);

    void cover() const;
    void uncover();
};

inline OwnerNode *Node1D::owner() const
{
  return d_owner;
}

inline Node1D *Node1D::prev() const
{
  return d_prev;
}

inline Node1D *Node1D::next() const
{
  return d_next;
}

#endif //SET2_NODE1D_H
