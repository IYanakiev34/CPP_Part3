#include <iostream>
#include "scanner.h"

using namespace std;

int main()
{
    size_t idCount = 0;
    size_t intCount = 0;
    size_t doubleCount = 0;
    size_t singleCharTokenCount = 0;
    size_t lineNumber = 1;
//#>42
    Scanner scanner;
    int tok = scanner.lex();
    cout << "1: ";
    while (tok)
    {
        switch (tok)
        {
            case IDENTIFIER: ++idCount; cout << scanner.matched(); break;
            case INTEGRAL: ++intCount; cout << scanner.matched(); break;
            case DOUBLE: ++doubleCount; cout << scanner.matched(); break;
            case LINENR:
                lineNumber = stoul(scanner.matched().substr(
                    3, scanner.matched().size())) - 1;
                break;
            case WHITESPACE: cout << scanner.matched(); break;
            case NEWLINE: lineNumber++; cout << '\n' << lineNumber << ": "; break;
            default: ++singleCharTokenCount; cout << static_cast<char>(tok); break;
        }
        tok = scanner.lex();
    }
    cout << '\n';
}