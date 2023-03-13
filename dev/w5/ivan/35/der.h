#ifndef EXMAPLE_1_INCLUDED_H
#define EXMAPLE_1_INCLUDED_H

#include "Deref/DerefConcept.h"

template <typename Data>
    requires Deref<Data> decltype(auto)
def1(Data *data)
{
    return *data;
}

#endif
