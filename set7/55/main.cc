#include "main.ih"

int main()
{
  bool debug = false;
  if (debug)
  {
    Scanner scanner;
    size_t token;
    while ((token = scanner.lex()))
      cout << (size_t) token << '\n';
  }
  else
  {
    Parser parser;
    while(parser.parse())
      ;
  }
}