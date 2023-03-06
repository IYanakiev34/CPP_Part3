#ifndef MERGE_H
#define MERGE_H

#include "Chars.h"
#include "OneChar.h"

template <typename First, typename Second>
struct Merge;

template <char... FirstChars, char... SecondChars>
struct Merge<Chars<FirstChars...>, Chars<SecondChars...>>
{
    using CP = Chars<FirstChars..., SecondChars...>;
};

template <char... FirstChars, char SecondChars>
struct Merge<Chars<FirstChars...>, OneChar<SecondChars>>
{
    using CP = Chars<FirstChars..., SecondChars>;
};

#endif