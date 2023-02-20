#ifndef COUNT_INCLUDED_H
#define COUNT_INCLUDED_H

#include <cstddef>

class Counter
{
    static std::size_t s_globalCount;
    static std::size_t s_actualCount;

public:
    Counter();
    ~Counter();
    static std::size_t getGlobalCount();
    static std::size_t getGlobalActual();
};

inline std::size_t Counter::getGlobalActual()
{
    return s_actualCount;
}

inline std::size_t Counter::getGlobalCount()
{
    return s_globalCount;
}

#endif