#ifndef ONE_CHAR_H
#define ONE_CHAR_H

template <char Character>
struct OneChar
{
    static constexpr char value = Character;

    constexpr operator char() const;
};

template <char Character>
constexpr OneChar<Character>::operator char() const
{
    return value;
}

#endif