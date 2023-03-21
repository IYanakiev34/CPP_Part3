#include "main.ih"

int main()
{
  Scanner scanner{"main.cc", "out"};

  size_t token;
  while ((token = scanner.lex()))
    if (token == Scanner::LINE)
                                    // Write source with line number
      cout << scanner.lineNr() << ": " << scanner.matched();
}