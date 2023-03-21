#include "main.ih"

int main()
try
{
  Scanner scanner{"test", "out"};

  while (scanner.lex())
    ;
}
catch (...)
{
  return 1;
}