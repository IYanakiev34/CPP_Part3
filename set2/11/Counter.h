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

    static std::size_t getGlobal()
    {
        return s_globalCount;
    }

    static std::size_t getActual()
    {
        return s_actualCount;
    }
};
#endif