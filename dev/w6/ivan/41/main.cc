#include "scanner.h"
#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>

void parseInputStream(Scanner &scanner, std::set<std::string> &words)
{
    int token = scanner.lex();
    while (token)
    {
        words.insert(scanner.matched());
        token = scanner.lex();
    }
}

int main(int argc, char **argv)
{
    Scanner scanner;
    std::set<std::string> words;

    if (argc > 1)
    {
        for (int idx = 1; idx != argc; ++idx)
        {
            scanner.switchIstream(argv[idx]);
            parseInputStream(scanner, words);
        }
    }
    else
    {
        parseInputStream(scanner, words);
    }

    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << '\n';

    return 0;
}