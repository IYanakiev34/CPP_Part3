#include "scanner.h"
#include <iostream>
#include <stack>
#include <set>

using namespace std;

int main()
{
    Scanner scanner;
    int tok = scanner.lex();
    while (tok)
    {
        if (tok == INCLUSION)
        {
            string fname = scanner.matched().substr(
                10, scanner.matched().size() - 11);
            scanner.addInclusion(fname);
        }
        tok = scanner.lex();
    }
    cout << '\n';
}
