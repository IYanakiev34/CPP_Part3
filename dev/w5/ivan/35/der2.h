#ifndef EXAMPLE_2_INCLUDED_H
#define EXAMPLE_2_INCLUDED_H

#include "Deref/DerefConcept.h"

template <Deref Der>
auto def1(Der data)
{
    return *data;
}

#endif