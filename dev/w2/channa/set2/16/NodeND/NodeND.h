#ifndef SET2_NODEND_H
#define SET2_NODEND_H

#include "../Node1D/Node1D.h"
#include "../OwnerNode/OwnerNode.h"

#include <cstddef>
#include <array>

template <size_t N>
class NodeND : public OwnerNode
{
  public:
    NodeND();

    void insert_back(NodeND &other, size_t dim);
    void insert_front(NodeND &other, size_t dim);

    NodeND<N> *prev(size_t dim) const;
    NodeND<N> *next(size_t dim) const;

    void cover(size_t dim) const;
    void uncover(size_t dim);
  private:
    std::array<Node1D, N> d_dims;
};

#include "NodeND.f"

#include "insert_back.f"
#include "insert_front.f"

#include "next.f"
#include "prev.f"

#include "cover.f"
#include "uncover.f"
#endif //SET2_NODEND_H
