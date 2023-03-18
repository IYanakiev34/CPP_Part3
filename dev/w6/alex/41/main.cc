#include "scanner.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    Scanner scanner;
    set<string> words;
    int tok;
    for (int idx = 1; idx != argc; ++idx)
    {
        scanner.switchIstream(argv[idx]);
        tok = scanner.lex();
        while (tok)
        {
            words.insert(scanner.matched());
            tok = scanner.lex();
        }
    }

    for (auto it = words.begin(); it != words.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
}