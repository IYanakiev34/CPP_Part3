#include "main.ih"

int main()
try
{
    Scanner scanner;
    while (scanner.lex())
        ;
}
catch (...)
{
  handleExceptions();
}