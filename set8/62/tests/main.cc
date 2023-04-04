#include "main.ih"

using namespace std;

string tokenToName(size_t token)
{
  if (token == Tokens::NAME)
    return "NAME";
  else if (token == Tokens::TOKEN)
    return "TOKEN";
  else
    return string{static_cast<char>(token)};
}

int main(int argc, char **argv)
try
{
    Parser parser;
    parser.parse();

    parser.printGrammarRules();
}
catch (...)
{
    cerr << "Terminating\n";
    return 1;
}

