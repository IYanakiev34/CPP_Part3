#ifndef CHARS_INCLUDED_H
#define CHARS_INCLUDED_H

template <char... chars>
struct Chars
{
    static constexpr char const value[] = {chars..., '\0'};

    constexpr operator char const *() const
    {
        return value;
    }
};

#endif