#ifndef BIT_H
#define BIT_H

#include <cstddef>

template <size_t N, size_t... Bits>
struct Bin
{
    static constexpr char const *value =
        Bin<(N >> 1),
            ((N & 1ull) ? 1ull : 0ull), Bits...>::value;
};

template <size_t... Bits>
struct Bin<0, Bits...>
{
    static constexpr char value[sizeof...(Bits) + 1] = {('0' + Bits)..., '\0'};
};

#endif