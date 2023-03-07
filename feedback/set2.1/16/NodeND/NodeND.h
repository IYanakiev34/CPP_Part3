//JB: ?
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
    //JB: Naming. This is not an array of dimensions.
};

#include "NodeND.f"

#include "insert_back.f"
#include "insert_front.f"

#include "next.f"
#include "prev.f"

#include "cover.f"
#include "uncover.f"
#endif //SET2_NODEND_H

/* JB:
   This is not a bad attempt.
   However, by exposing 'dim' in both insert_* and prev/next, you burden the
   user with keeping track of which direction to connect in, and you don't
   even protect them from connecting in directions that don't exist.
   With templates, we could do better.
 */
