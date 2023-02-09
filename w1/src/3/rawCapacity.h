#ifndef RAW_CAP_H
#define RAW_CAP_H

#include <iosfwd>

template <typename T>
T* rawCapacity(std::size_t const capacity)
{
    return static_cast<T*>(operator new(capacity * sizeof(T)));
}
 
#endif
