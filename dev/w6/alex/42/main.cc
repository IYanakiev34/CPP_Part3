#include "scanner.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayTok(int tok)
{
    switch (tok)
    {
        case IDENTIFIER: cout << "IDENTIFIER "; break;
        case INTEGRAL: cout << "INTEGRAL "; break;
        case REAL: cout << "REAL "; break;
        case OPERATOR: cout << "OPERATOR "; break;
        case STRING: cout << "STRING "; break;
        case CHARACTER: cout << "CHARACTER "; break;
        case NEWLINE: cout << '\n'; break;
        default: 
            char toChar = static_cast<char>(tok);
            cout << toChar;
            break;
    }
}

int main()
{
    Scanner scanner;
    vector<string> matches;
    int tok = scanner.lex();
    while (tok)
    {
        displayTok(tok);
        tok = scanner.lex();
        matches.push_back(scanner.matched());
    }
    cout << "\n----------------------------------------\n";
    for (auto it = matches.begin(); it != matches.end(); ++it)
        cout << *it << ' ';
}