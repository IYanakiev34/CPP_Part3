#ifndef HOLDER_INCLUDED_H
#define HOLDER_INCLUDED_H

#include "../Deref/DerefConcept.h"

template <typename Data>
    requires Deref<Data>
class Holder
{
    Data d_data;

public:
    Holder(Data data);
};

template <typename Data>
    requires Deref<Data>
Holder<Data>::Holder(Data data)
    : d_data(data)
{
}

#endif
