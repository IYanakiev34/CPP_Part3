#include "scanner.h"
#include <iostream>

int main()
try
{
    Scanner scanner;
    while (scanner.lex())
        ;
}
catch (...)
{
    return 1;
}