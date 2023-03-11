#ifndef SET5_DEREF_H
#define SET5_DEREF_H

#include "../Dereferenceable/Dereferenceable.h"

template <typename Type>
  requires Dereferenceable<Type>
class Deref
{
    Type d_deref;

  public:
    Deref(Type deref);
};

#endif //SET5_DEREF_H
