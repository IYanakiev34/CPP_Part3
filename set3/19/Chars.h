#ifndef CHARS_INCLUDED_H
#define CHARS_INCLUDED_H

template <char... Characters>
struct Chars
{
    static constexpr char const value[] = {Characters..., '\0'};
    constexpr operator char const *() const;
};

template <char... Characters>
constexpr Chars<Characters...>::operator char const *() const
{
    return value;
}

#endif