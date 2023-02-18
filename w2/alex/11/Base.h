//
// Created by Alex Swaters on 2/18/2023.
//

#ifndef INC_11_BASE_H
#define INC_11_BASE_H

#include <cstddef>

class Base
{
protected:
    static size_t s_globalCount;
    static size_t s_globalActual;
public:
    static size_t globalCount();
    static size_t globalActual();
};

inline size_t Base::globalCount()
{
    return s_globalCount;
}

inline size_t Base::globalActual()
{
    return s_globalActual;
}

#endif //INC_11_BASE_H
