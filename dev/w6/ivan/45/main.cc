#include <iostream>
#include "scanner.h"

#define MOVE(id) ++id;
#define PRINT                       \
    std::cout << scanner.matched(); \
    break;

#define PRINTANDMOVE(id) MOVE(id) PRINT;

int main()
{
    size_t ident, ints, doubles, chars, lineNr = 0;
    ++lineNr;

    // #>42
    Scanner scanner;

    int token = scanner.lex();

    while (token)
    {
        switch (token)
        {
        case IDENTIFIER:
            PRINTANDMOVE(ident);
            break;
            break;
        case DOUBLE:
            PRINTANDMOVE(doubles);
            break;
        case INTEGRAL:
            PRINTANDMOVE(ints)
            break;
        case LINENR:
            lineNr = std::stoull(scanner.matched().substr(3, scanner.matched().size())) - 1;
            break;
        case WHITESPACE:
            PRINT;
        case NEWLINE:
            ++lineNr;
            std::cout << '\n'
                      << lineNr << ": ";
            break;
        default:
            ++chars;
            std::cout << static_cast<char>(token);
            break;
        }

        token = scanner.lex();
    }
    return 0;
}