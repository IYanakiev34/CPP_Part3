#ifndef NRTRAIT_H
#define NRTRAIT_H

#include <cstddef>
#include <string>

template <size_t N>
struct NrTrait
{
    static constexpr size_t value = N;
    static constexpr bool even = (N % 2 == 0);
    static constexpr bool by3 = (N % 3 == 0);

private:
    template <size_t M, size_t D = 0>
    struct WidthHelper
    {
        static constexpr size_t value = WidthHelper<M / 10, D + 1>::value;
    };

    template <size_t D>
    struct WidthHelper<0, D>
    {
        static constexpr size_t value = D;
    };

public:
    static constexpr size_t width = WidthHelper<N>::value;
};

#endif