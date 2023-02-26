#ifndef I2C_H
#define I2C_H

#include <cstddef>

template <size_t N, char... Chars>
struct I2C
{
    static constexpr char const *s_ntbs = I2C<(N / 10), static_cast<char>(N % 10), Chars...>::s_ntbs;
};

template <char... Chars>
struct I2C<0, Chars...>
{
    static constexpr char const s_ntbs[] = {('0' + Chars)..., '\0'};
};

template <>
struct I2C<0>
{
    static constexpr char const s_ntbs[] = {'0'};
};

#endif