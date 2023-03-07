#ifndef TYPE_INCLUDED_H
#define TYPE_INCLUDED_H

                              // We will specialize Type. It will contain
                              // TypeIdx which will contain the location to
                              // find if a type is in variadic template argument
template <typename ...Types>
class Type
{};
                              // To encode our logic in TypeIdx, we specialize
                              // Type for the cases we encounter, and then
                              // define our logic in a definition of TypeIdx
                              // (based on the specialized outer class)
                              // subsequently.
#include "generalCase.f"
#include "notFoundCase.f"
#include "foundCase.f"

#endif