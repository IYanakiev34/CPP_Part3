#ifndef SET3_TYPE_H
#define SET3_TYPE_H

template <typename ...Types>
struct Type
{};

                    // General case: Needle =/= Head, keep on searching
template<typename Needle, typename Head, typename ...Rest>
struct Type<Needle, Head, Rest...>
{
  enum
  {
    index = Type<Needle, Rest...>::located,
    located = index == 0 ? 0 : Type<Needle, Rest...>::located + 1
  };
};

                      // Base case 1: Cannot find needle
template <typename Needle>
struct Type<Needle>
{
  enum
  {
    located = 0
  };
};
                // Base case 2: Found needle
template<typename Needle, typename ...Rest>
struct Type<Needle, Needle, Rest...>
{
  enum
  {
    located = 1
  };
};

#endif //SET3_TYPE_H
