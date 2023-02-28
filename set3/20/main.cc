#include "Merge.h"
#include <iostream>

int main()
{
    std::cout << Merge<
                     Chars<'1', '2', '3'>,
                     Merge<Chars<'4', '5'>, OneChar<'6'>>::CP>::CP{}
              << '\n';
}