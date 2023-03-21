#include "main.ih"

int main()
{
  Scanner scanner{"test", "out"};

  size_t token;
  while ((token = scanner.lex()))
    writeMatched(cout, scanner.matched(), token);
}