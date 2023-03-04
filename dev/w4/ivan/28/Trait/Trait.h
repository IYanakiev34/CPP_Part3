#ifndef TRAIT_INCLUDED_H
#define TRAIT_INCLUDED_H

template <typename T>
struct TypeTrait
{
    static const int value = 1;
};

template <typename T>
struct TypeTrait<T *>
{
    static const int value = 2;
};

template <typename T>
struct TypeTrait<T &>
{
    static const int value = 3;
};

template <typename T>
struct TypeTrait<T &&>
{
    static const int value = 4;
};

#endif