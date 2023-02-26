#ifndef SET3_CHARS_H
#define SET3_CHARS_H

template<char ...chars>
struct Chars
{
                          // contexpr is important, if we want to access the
                          // characters pass to this template at compile-time.

                          // We create s_str by unpacking chars and appending
                          // the null byte to it. The compiler is smart enough
                          // to determine the length, so we can use [] here.
  static constexpr char const s_str[] = {chars..., '\0'};

  Chars() = default;

  constexpr operator char const *() const;
};

template <char ...chars>
inline constexpr Chars<chars...>::operator char const *() const
{
  return s_str;
}

#endif //SET3_CHARS_H
