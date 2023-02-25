#ifndef SET3_CHARS_H
#define SET3_CHARS_H

template<char ...chars>
struct Chars
{
  static constexpr char const s_str[] = {chars..., '\0'};

  Chars() = default;

  constexpr operator char const *() const;
};

template <char ...chars>
inline constexpr Chars<chars...>::operator char const *() const
{
  return s_str;
}
#include "convertToNTBS.f"

#endif //SET3_CHARS_H
