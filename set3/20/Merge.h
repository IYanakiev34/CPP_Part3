#ifndef MERGE_H
#define MERGE_H

#include "Chars.h"
#include "OneChar.h"

                            // Merge is a template class that takes either:
                            // * Two Chars template classes
                            // * A Chars and OneChar template class
                            // It _merges_ these template classes by holding a
                            // type CP.
                            // CP is a Chars class containing the
                            // character template arguments in the first Chars
                            // class followed by the character template
                            // arguments in the second Chars / OneChar class.
template <typename First, typename Second>
struct Merge;

                            // Case 1: We get two Chars classes
template <char... FirstChars, char... SecondChars>
struct Merge<Chars<FirstChars...>, Chars<SecondChars...>>
{
                              // expand the parameter packs in order
    using CP = Chars<FirstChars..., SecondChars...>;
};

                          // Case 2: We get a Chars class and then a OneChar
                          // class
template <char... FirstChars, char SecondChars>
struct Merge<Chars<FirstChars...>, OneChar<SecondChars>>
{
                                  // append OneChar character parameter to
                                  // expanded Chars variadic argument.
    using CP = Chars<FirstChars..., SecondChars>;
};

#endif