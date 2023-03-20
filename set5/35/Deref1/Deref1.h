#ifndef SET5_DEREF1_H
#define SET5_DEREF1_H

#include "../Dereferenceable/Dereferenceable.h"

                              // Class demoing using a concept explicitly, in
                              // a requires clause
template <typename Type>
  requires Dereferenceable<Type>
class Deref1
{
    Type d_deref;

  public:
    Deref1(Type deref);
};

template<typename Type>
  requires Dereferenceable<Type>
Deref1<Type>::Deref1(Type deref)
  : d_deref(deref)
{}

#endif //SET5_DEREF1_H
