#include "main.ih"

#include "../Scanner/Scanner.h"

int main()
{
  Scanner scanner;

  while(scanner.lex())
    cout << "Scanned: " << scanner.matched() << '\n';
}