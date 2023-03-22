#include "scanner.h"
#include <iostream>

int main()
{
    Scanner scanner;
    int token = scanner.lex();
    while (token)
    {
        std::cout << scanner.matched();
        token = scanner.lex();
    }
}