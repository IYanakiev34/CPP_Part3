#include "parser.ih"

void Parser::error(char const *msg)
{
    cout << "syntax error\n";
    d_display = false;
}
