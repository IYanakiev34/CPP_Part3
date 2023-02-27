#ifndef SOL_H
#define SOL_H

#include "../20/Merge.h"
#include "../20/OneChar.h"

template <int Value, int Radix, bool Displayed = false>
struct Display
{
    using CP = typename Merge<typename Display<Value / Radix, Radix, Value != 0>::CP, OneChar<"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[Value % Radix]>>::CP;
};

template <int Value, int Radix>
struct Display<Value, Radix, true>
{
    using CP = typename Merge<typename Display<Value / Radix, Radix, Value != 0>::CP, OneChar<"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[Value % Radix]>>::CP;
};

template <int Radix, bool Displayed>
struct Display<0, Radix, Displayed>
{
    using CP = typename Merge<typename std::conditional<Displayed, OneChar<'0'>, Chars<>>::type, Chars<>>::type;
};

template <int Value, int Radix>
struct Convert
{
    using CP = typename Display<Value, Radix>::CP;
};

#endif