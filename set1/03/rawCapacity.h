#ifndef SET1_RAW_CAPACITY_H
#define SET1_RAW_CAPACITY_H

#include <memory>

template <typename ReturnType>
ReturnType *rawCapacity(size_t capacity)
{
  return static_cast<ReturnType *>(operator new(
                                    // We receive capacity as number of elements
                                    // so we need to determine number of bytes
                                    // to give placement new.
    sizeof(ReturnType) * capacity
  ));
}

#endif //SET1_RAW_CAPACITY_H
