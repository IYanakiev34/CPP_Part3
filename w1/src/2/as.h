#ifndef AS_H
#define AS_H


template <typename T, typename S>
inline T as(S &&source)
{
    return static_cast<T>(source);
}

#endif
