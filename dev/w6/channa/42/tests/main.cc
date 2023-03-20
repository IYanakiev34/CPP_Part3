#include "main.ih"

int main()
{
  Scanner scanner;

  size_t token;
  while ((token = scanner.lex()))
    writeMatched(cout, scanner.matched(), token);
}