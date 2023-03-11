#ifndef SET5_FWDITERATOR_H
#define SET5_FWDITERATOR_H

#include "BasicIterators.h"

template <typename Type>
concept FwdIterator =
InIterator<Type> and OutIterator<Type>;

#endif //SET5_FWDITERATOR_H
