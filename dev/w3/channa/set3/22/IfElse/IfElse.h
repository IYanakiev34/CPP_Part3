#ifndef SET3_IFELSE_H
#define SET3_IFELSE_H

template <bool cond, typename T1, typename T2>
struct IfElse
{};

template <typename T1, typename T2>
struct IfElse<true, T1, T2>
{
  using type = T1;
};

template <typename T1, typename T2>
struct IfElse<false, T1, T2>
{
  using type = T2;
};

#endif //SET3_IFELSE_H
