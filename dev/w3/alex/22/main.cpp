#include <iostream>

template<char... Characters>
struct Chars
{
    static constexpr char const value[] = {Characters..., '\0'};

    constexpr operator char const *() const;
};

template<char... Characters>
constexpr Chars<Characters...>::operator char const *() const
{
    return value;
}

template<size_t Value, size_t Base, char... Characters>
struct Display
{
    using CP = typename Display<
            Value / Base,
            Base,
            Value % Base < 10
                ? Value % Base + '0'
                : Value % Base + 'a' - 10,
            Characters...>::CP;
};

template<size_t Base, char... Characters>
struct Display<0, Base, Characters...>
{
    using CP = Chars<Characters...>;
};

template<size_t Value, size_t Base>
struct Convert
{
    using CP = typename Display<Value, Base>::CP;
};

int main()
{
    std::cout << Convert<57005, 8>::CP{} << '\n';    // displays '157255'
    std::cout << Convert<57005, 16>::CP{} << '\n';   // displays 'dead'
    std::cout << Convert<57005, 32>::CP{} << '\n';   // displays '1nld'
}