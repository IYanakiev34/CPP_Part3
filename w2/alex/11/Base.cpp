//
// Created by Alex Swaters on 2/18/2023.
//

#include "Base.h"
size_t Base::s_globalActual = 0;
size_t Base::s_globalCount = 0;

Base::Base()
{
    s_globalActual++;
    s_globalCount++;
}

Base::~Base()
{
    s_globalActual--;
}