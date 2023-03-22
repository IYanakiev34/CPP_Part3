#include "scanner.h"
#include <iostream>

int main()
{
    Scanner scanner;
    while (scanner.lex())
        ;
}