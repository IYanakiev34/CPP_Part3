#ifndef SET2_SIMPLEPOINTER_H
#define SET2_SIMPLEPOINTER_H

#include "Simple.h"

template <typename Data>
class Simple<Data *>
{
  Data *d_ptr = 0;

  public:
    Simple() = default;
    explicit Simple(Data &data);
    explicit Simple(Data *other );

    Data &get();
};

template <typename Data>
Simple<Data *>::Simple(Data &data)
  :
  d_ptr(&data)
{}

template <typename Data>
Simple<Data *>::Simple(Data *const other)
  :
  d_ptr(other)
{}

template <typename Data>
Data &Simple<Data *>::get()
{
  return *d_ptr;
}

#endif //SET2_SIMPLEPOINTER_H
