#ifndef SET5_SORTWITHCONCEPTS_H
#define SET5_SORTWITHCONCEPTS_H

#include "IteratorConcepts/RndIterator.h"

#include <algorithm>

                          // Sort, but the inputs are verified via concepts to
                          // be Random Access Iterators
template <RndIterator RAI>
void sortWithConcepts(RAI first, RAI last)
{
std::sort(first, last);
}

#endif //SET5_SORTWITHCONCEPTS_H
