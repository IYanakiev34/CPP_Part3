#ifndef TYPE_INCLUDED_H
#define TYPE_INCLUDED_H

template <typename Needle, typename... Haystack>
class Type
{
private:
    template <typename... Types>
    struct TypeIdx
    {
    };

    template <typename Needle2>
    struct TypeIdx<Needle2>
    {
        enum
        {
            located = 0
        };
    };

    template <typename Needle2, typename... Haystack2>
    struct TypeIdx<Needle2, Needle2, Haystack2...>
    {
        enum
        {
            located = 1
        };
    };

    template <typename Needle2, typename First, typename... Haystack2>
    struct TypeIdx<Needle2, First, Haystack2...>
    {
        enum
        {
            located = Type<Needle2, Haystack2...>::located
                          ? Type<Needle2, Haystack2...>::located + 1
                          : 0
        };
    };

public:
    enum
    {
        located = TypeIdx<Needle, Haystack...>::located
    };
};

#endif