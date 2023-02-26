#ifndef SET3_GENERATEREP_H
#define SET3_GENERATEREP_H

#include "GenerateRepRec.h"
#include "../IfElse/IfElse.h"

                                // GenerateRep is simply a wrapper to use
                                // GenerateRepRec
template <size_t num, size_t radix, char ...rep>
struct GenerateRep
{
                                // GenerateRepRec cannot handle num == 0, so
                                // we handle it directly
  using CP = typename IfElse<num == 0,
    Chars<'0'>, typename GenerateRepRec<num, radix, rep...>::CP
  >::type;
};

#endif //SET3_GENERATEREP_H
