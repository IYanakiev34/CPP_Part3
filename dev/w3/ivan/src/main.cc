#include <iostream>

// Exercise 17
// #include "17/nrtrait.h"

// Exercise 18
#include "18/Bit.h"

// Exercise 19
// #include "19/chars.h"

int main(int argc, char **argv)
{
    // 17
    /*
    std::cout << "Value: " << NrTrait<1971962>::value
              << ", Even: " << NrTrait<1971962>::even
              << ", Divisible by 3: " << NrTrait<1971962>::by3
              << ", Width: " << NrTrait<1971962>::width << std::endl;
    */

    // 18
    std::cout << Bin<5>::value << "\n";
    std::cout << Bin<27>::value << "\n";

    // 19
    return 0;
}