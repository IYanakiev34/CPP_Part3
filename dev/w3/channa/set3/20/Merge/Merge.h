#ifndef SET3_MERGE_H
#define SET3_MERGE_H

#include "../OneChar/OneChar.h"
#include "../Chars/Chars.h"
#include "../Chars/Tail.h"

                      // Idea: Unpack First / Second into all
template <typename First, typename Second, char ...all>
struct Merge
{
                          // We add the head of First to the end of all since
                          // after going through the recursion to have First be
                          // empty, all will be in the right order
  using CP = typename Merge<
    typename Tail<First>::tail,
    Second,
    all..., *First{}
  >::CP;
};

                      // Finished unpacking First, now unpack second
template <typename Second, char ...all>
struct Merge<Chars<>, Second, all...>
{
                      // Unpack second as first, with OneChar<'\0'> as the
                      // ending sentinel.
  using CP = typename Merge<Second, Chars<>, all...>::CP;
};

                    // Base case 1: We were merging two Chars
template <char ...all>
struct Merge<Chars<>, Chars<>, all...>
{
  using CP = Chars<all...>;
};

                        // Base case 2: We were merging Chars and OneChar
template <char ch, char ...all>
struct Merge<Chars<>, OneChar<ch>, all...>
{
  using CP = Chars<all..., ch>;
};

#endif //SET3_MERGE_H
