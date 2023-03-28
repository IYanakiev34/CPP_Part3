#include "main.ih"

int main()
try
{
  Scanner scanner{"main.cc", "out"};

  while (scanner.lex());
}
catch (...)
{
  handleExceptions();
}