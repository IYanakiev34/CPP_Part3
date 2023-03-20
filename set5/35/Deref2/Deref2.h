#ifndef SET5_DEREF2_H
#define SET5_DEREF2_H

#include "../Dereferenceable/Dereferenceable.h"

                              // Class demoing using a concept explicitly, in
                              // a requires clause
template <Dereferenceable Type>
class Deref2
{
    Type d_deref;

  public:
    Deref2(Type deref);
};

template<Dereferenceable Type>
Deref2<Type>::Deref2(Type deref)
  : d_deref(deref)
{}

#endif //SET5_DEREF2_H
