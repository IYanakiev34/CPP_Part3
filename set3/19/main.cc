#include "Chars.h"
#include <iostream>
int main()
{
    std::cout << Chars<'h', 'e', 'l', 'l', 'o'>() << '\n'
              << Chars<'m', 'e', 't', 'a'>() << Chars<>() << '\n';
}