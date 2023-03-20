#ifndef SET5_DEREFERENCE2_H
#define SET5_DEREFERENCE2_H

#include "Dereferenceable/Dereferenceable.h"

                              // An implicit function template that shows the
                              // use a concept in the parameter list.
auto dereference2(Dereferenceable auto toDeref)
{
  return *toDeref;
}

#endif //SET5_DEREFERENCE2_H
