//JB: 0
#ifndef SET2_NODEND_H
#define SET2_NODEND_H

#include "../Node1D/Node1D.h"

#include <cstddef>

template <size_t N>
class NodeND : public Node1D
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

/* JB:
   IMO private data is better than protected.
   In the NodeND case, NodeND itself will segfault because it lacks a
   user-defined copy constructor. But because the data is protected, I have to
   hunt down all derived classes and see if they perhaps deal with the problem
   so the program is safe after all. That's bad design IMO.

   Moreover, WHEEL. Facilities for a safely allocated array of Node1Ds already
   exist.

   And yet (hint) such an array isn't as safe as I'd like it, because the
   types of d_dims[0] and d_dims[1] are identical, so the directions
   (left-right and up-down) could become mixed up.
 */
