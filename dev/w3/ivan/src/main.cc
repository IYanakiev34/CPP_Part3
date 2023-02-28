#include <iostream>

// Exercise 17
// #include "17/nrtrait.h"

// Exercise 18
// #include "18/Bit.h"

// Exercise 19
// #include "19/Chars.h"

// Exercise 20
// #include "20/Merge.h"

// Exercise 22
// #include "22/sol.h"

// Exercise 24
#include "24/I2C.h"

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
    /*
    std::cout << Bin<5>::value << "\n";
    std::cout << Bin<27>::value << "\n";
    */

    // 19
    /*
    std::cout << Chars<'h', 'e', 'l', 'l', 'o'>() << '\n';
    std::cout << Chars<'m', 'e', 't', 'a'>() << '\n';
    std::cout << Chars<>() << '\n';
    */

    // 20
    /*
    std::cout << Merge<Chars<'1', '2', '3'>,
                       Merge<Chars<'4', '5'>, OneChar<'6'>>::CP>::CP{}
              << '\n';
    */

    // 24
    std::cout << I2C<123>::s_ntbs << '\n';
    std::cout << I2C<0>::s_ntbs << '\n';
    std::cout << I2C<15937>::s_ntbs << '\n';
    std::string value{I2C<15937>::s_ntbs};
    std::cout << value << '\n';

    return 0;
}