#ifndef SET5_DEREFERENCE1_H
#define SET5_DEREFERENCE1_H

#include "Dereferenceable/Dereferenceable.h"

                                // A function template showing the use of a
                                // concept directly when declaring the template
                                // type parameter.
template <Dereferenceable Deref>
auto dereference1(Deref toDeref)
{
return *toDeref;
}

#endif //SET5_DEREFERENCE1_H
