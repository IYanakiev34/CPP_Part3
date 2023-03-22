#include "scanner.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

void showToken(int tok)
{
    switch (tok)
    {
    case IDENTIFIER:
        std::cout << "IDENTIFIER ";
        break;
    case REAL:
        std::cout << "REAL ";
        break;
    case INTEGRAL:
        std::cout << "INTEGRAL ";
        break;
    case STRING:
        std::cout << "STRING ";
        break;
    case NEWLINE:
        std::cout << "\n";
        break;
    case CHARACTER:
        std::cout << "CHARACTER ";
        break;
    case OPERATOR:
        std::cout << "OPERATOR ";
        break;
    default:
        std::cout << static_cast<char>(tok);
        break;
    }
}

int main()
{
    Scanner scanner;
    std::vector<std::string> words;
    int token = scanner.lex();

    while (token)
    {
        showToken(token);
        token = scanner.lex();
        words.push_back(scanner.matched());
    }

    std::cout << '\n';
    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << '\n';

    return 0;
}