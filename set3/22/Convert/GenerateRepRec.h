#ifndef SET3_GENERATEREPREC_H
#define SET3_GENERATEREPREC_H

#include "../Chars/Chars.h"
#include "../Rep/Rep.h"

#include <cstddef>

                                      // We store the representation in the rep
                                      // parameter pack
template <size_t num, size_t radix, char ...rep>
struct GenerateRepRec
{
                                      // We essentially compute the
                                      // representation of the right most digit
                                      // and store in rep, and compute the
                                      // rest via a recursive call.
  using CP = typename GenerateRepRec<
    num / radix,
    radix,
    Rep<num % radix, radix>::rep, rep...
  >::CP;
};

                                      // In the base case where there is no more
                                      // numbers to compute (which we signal
                                      // with num = 0, we store the
                                      // representation in Chars
template <size_t radix, char ...rep>
struct GenerateRepRec<0, radix, rep...>
{
  using CP = Chars<rep...>;
};

#endif //SET3_GENERATEREPREC_H
