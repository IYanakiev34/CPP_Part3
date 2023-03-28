#include "main.ih"

int main()
{
  if (true)
  {
    Scanner scanner;
    size_t token;
    while ((token = scanner.lex()));
  }
  else
  {
    Parser parser;
    while(parser.parse())
      ;
  }
}