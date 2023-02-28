//JB: 0
#ifndef SET2_NODEND_H
#define SET2_NODEND_H

#include "../Node1D/Node1D.h"

#include <cstddef>

template <size_t N>
class NodeND
{
  public:
    NodeND();
    ~NodeND();

  protected:
    Node1D *d_dims[N];
};

#include "NodeND.f"
#include "dtor.f"

#endif //SET2_NODEND_H