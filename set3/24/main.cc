#include "I2C.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << I2C<123>::s_ntbs << '\n'
              <<                // shows 123
        I2C<0>::s_ntbs << '\n'; // shows 0

    std::string value{I2C<15937>::s_ntbs};

    std::cout << value << '\n'; // shows 15937
}