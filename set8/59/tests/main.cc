#include "main.ih"

using namespace std;

int main(int argc, char **argv)
try
{
  bool debug = false;
  if (debug)
  {
    Scanner scanner;
    size_t token;
    while ((token = scanner.lex()))
      cout << token << '\n';
  }
  else
  {
    Parser parser;
    return parser.parse();
  }
}
catch (...)
{
  cerr << "Terminating\n";
  return 1;
}

