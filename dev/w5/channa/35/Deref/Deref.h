#ifndef SET5_DEREF_H
#define SET5_DEREF_H

#include "../Dereferenceable/Dereferenceable.h"

                              // Class demoing using a concept explicitly, in
                              // a requires clause
template <typename Type>
  requires Dereferenceable<Type>
class Deref
{
    Type d_deref;

  public:
    Deref(Type deref);
};

template<typename Type>
requires Dereferenceable<Type> Deref<Type>::Deref(Type deref)
  : d_deref(deref)
{}

#endif //SET5_DEREF_H
