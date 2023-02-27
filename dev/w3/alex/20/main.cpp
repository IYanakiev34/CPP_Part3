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

template<char Character>
struct OneChar
{
    static constexpr char value = Character;

    constexpr operator char() const;
};

template<char Character>
constexpr OneChar<Character>::operator char() const
{
    return value;
}

template<typename First, typename Second>
struct Merge;

template<char... FirstChars, char... SecondChars>
struct Merge<Chars<FirstChars...>, Chars<SecondChars...>>
{
    using CP = Chars<FirstChars..., SecondChars...>;
};

template<char... FirstChars, char SecondChars>
struct Merge<Chars<FirstChars...>, OneChar<SecondChars>>
{
    using CP = Chars<FirstChars..., SecondChars>;
};

int main()
{
    std::cout <<
              Merge<
                      Chars<'1', '2', '3'>,
                      Merge<Chars<'4', '5'>, OneChar<'6'>>::CP
              >::CP{} << '\n';
}
