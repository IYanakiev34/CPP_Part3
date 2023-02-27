#include <iostream>

template <size_t number>
struct NrTrait
{
    enum
    {
        value = number,
        even = number % 2 == 0,
        by3 = number % 3 == 0,
        width = number < 10 ? 1 : 1 + NrTrait<number / 10>::width
    };
};

template <>
struct NrTrait<0>
{
    enum
    {
        width = 1
    };
};

int main()
{
    std::cout <<
        NrTrait<123>::value << '\n' <<
        NrTrait<123>::even << '\n' <<
        NrTrait<12>::even << '\n' <<
        NrTrait<8375>::by3 << '\n' <<
        NrTrait<375>::by3 << '\n' <<
        NrTrait<8375>::width << '\n';

    NrTrait<1971962> test;
    std::cout <<
        "Even? " << test.even << '\n' <<
        "Divisible by 3? " << test.by3 << '\n' <<
        "Width? " << test.width << '\n';
}
