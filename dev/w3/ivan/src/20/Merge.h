#ifndef MERGE_INCLUDED_H
#define MERGE_INCLUDED_H

#include "../19/Chars.h"
#include "OneChar.h"

template <typename Lhs, typename Rhs>
struct Merge;

template <char... lhs_chars, char... rhs_chars>
struct Merge<Chars<lhs_chars...>, Chars<rhs_chars...>>
{
    using CP = Chars<lhs_chars..., rhs_chars...>;
};

template <char... lhs_chars, char rhs_char>
struct Merge<Chars<lhs_chars...>, OneChar<rhs_char>>
{
    using CP = Chars<lhs_chars..., rhs_char>;
};

template <char lhs_char, char... rhs_chars>
struct Merge<OneChar<lhs_char>, Chars<rhs_chars...>>
{
    using CP = Chars<lhs_char, rhs_chars...>;
};

template <char lhs_char, char rhs_char>
struct Merge<OneChar<lhs_char>, OneChar<rhs_char>>
{
    using CP = Chars<lhs_char, rhs_char>;
};
#endif
