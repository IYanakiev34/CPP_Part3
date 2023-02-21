#include "main.ih"

template <typename Target, typename Source>
inline Target as(Source &&value)
{
    return static_cast<Target>(value);
}