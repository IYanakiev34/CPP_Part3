#include <iostream>
#include "add.h"
#include "pu.h"

void fun()
{
    PointerUnion pu = { add };

    std::cout << pu.vp << "\n";
}
