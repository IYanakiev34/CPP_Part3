#include "scanner.h"
#include <iostream>

int main()
{
    Scanner scanner;
    int tok = scanner.lex();
    while (tok)
    {
        std::cout << scanner.matched();
        tok = scanner.lex();
    }
}