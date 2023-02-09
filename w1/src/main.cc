#include <iostream>
#include "1/add.h"
#include "1/pu.h"

void fun();


int main(int argc, char **argv)
{
    PointerUnion pu = { add };

    fun();
    std::cout << pu.vp << '\n';

    return 0;
}
