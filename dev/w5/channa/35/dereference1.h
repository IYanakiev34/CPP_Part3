#ifndef SET5_DEREFERENCE1_H
#define SET5_DEREFERENCE1_H

#include "Dereferenceable/Dereferenceable.h"

template <Dereferenceable Deref>
auto dereference1(Deref toDeref)
{
return *toDeref;
}

#endif //SET5_DEREFERENCE1_H
