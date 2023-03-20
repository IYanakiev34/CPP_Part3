#include "main.ih"

#include "../Scanner/Scanner.h"

int main()
{
  Scanner scanner{"test", "null"};

  while(scanner.lex())
    cout << "Scanned: " << scanner.matched() << '\n';
}