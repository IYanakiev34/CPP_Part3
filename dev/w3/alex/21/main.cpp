#include <iostream>

template <typename ...Types>
struct Type {};

// Only have needle means can't find in haystack
template <typename Needle>
struct Type<Needle>
{
    enum
    {
        located = 0
    };
};

// Found needle at first position
template <typename Needle, typename... Haystack>
struct Type<Needle, Needle, Haystack...>
{
    enum
    {
        located = 1
    };
};

// Needle is not at first position but haystack remains
template <typename Needle, typename First, typename... Haystack>
struct Type<Needle, First, Haystack...>
{
    enum
    {
        located = Type<Needle, Haystack...>::located
                ? Type<Needle, Haystack...>::located + 1
                : 0
    };
};

int main()
{
    std::cout <<
         Type<int>::located << ' ' <<
         Type<int, double>::located << ' ' <<
         Type<int, int>::located << ' ' <<
         Type<int, double, int>::located << ' ' <<
         Type<int, double, int>::located << ' ' <<
         Type<int, double, int, int, int>::located <<
         '\n';
}

