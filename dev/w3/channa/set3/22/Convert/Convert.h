#ifndef SET3_CONVERT_H
#define SET3_CONVERT_H

#include "../Rep/Rep.h"
#include "../IfElse/IfElse.h"
#include "../Chars/Chars.h"

template <size_t num, size_t radix, char ...rep>
struct GenerateRepRec
{
  using CP = typename GenerateRepRec<
    num / radix,
    radix,
    Rep<num, radix>::rep, rep...
  >::CP;
};

template <size_t radix, char ...rep>
struct GenerateRepRec<0, radix, rep...>
{
  using CP = Chars<rep...>;
};

template <size_t num, size_t radix, char ...rep>
struct GenerateRep
{
  using CP = typename IfElse<num == 0,
    Chars<'0'>, typename GenerateRepRec<num, radix, rep...>::CP
  >::type;
};

template <size_t num, size_t radix, char ...rep>
struct Convert
{
  using CP = typename GenerateRep<num, radix, rep...>::CP;
};

#endif //SET3_CONVERT_H
