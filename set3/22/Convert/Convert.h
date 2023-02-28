#ifndef SET3_CONVERT_H
#define SET3_CONVERT_H

#include "GenerateRep.h"

                        // We store the converted number's representation in
                        // the rep parameter pack
template <size_t num, size_t radix, char ...rep>
struct Convert
{
                        // We use GenerateRep as the auxiliary class to generate
                        // the representation.
  using CP = typename GenerateRep<num, radix, rep...>::CP;
};

#endif //SET3_CONVERT_H
