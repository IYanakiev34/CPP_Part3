#ifndef SET4_MAKECONSTPTR_H
#define SET4_MAKECONSTPTR_H

#include "Trait/Trait.h"

template<typename Type>
typename Trait<Type>::BasicType const *makeConstPtr(Type arg) {
  if constexpr (Trait<Type>::value == 2)
    return arg;
  else if constexpr (Trait<Type>::value == 3)
    return &arg;
  else
    return new typename Trait<Type>::BasicType{arg};
}

#endif //SET4_MAKECONSTPTR_H
