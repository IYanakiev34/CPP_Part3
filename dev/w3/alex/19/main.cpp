#include <iostream>

template <char... Characters>
struct Chars {
    static constexpr char const value[] = {Characters..., '\0'};
    constexpr operator char const *() const;
};

template<char... Characters>
constexpr Chars<Characters...>::operator char const *() const
{
    return value;
}

int main()
{
    std::cout << Chars<'h', 'e', 'l', 'l', 'o'>() << '\n' <<
         Chars<'m', 'e', 't', 'a'>() <<
         Chars<>() << '\n';
}