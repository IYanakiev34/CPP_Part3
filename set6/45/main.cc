#include "main.ih"

using namespace std;

int main()
{
  size_t idCount = 0;
  size_t intCount = 0;
  size_t doubleCount = 0;
  size_t singleCharTokenCount = 0;
  size_t lineNumber = 1;

  Scanner scanner{"main.cc", "out"};
  size_t tok = scanner.lex();
  cout << "1: ";
  while (tok)
  {
    std::string const &match = scanner.matched();
    if (tok != Scanner::LINENR && tok != Scanner::NEWLINE)
      cout << match;
    switch (tok)
    {
      case Scanner::IDENTIFIER:
        ++idCount;
        break;
      case Scanner::INTEGRAL:
        ++intCount;
        break;
      case Scanner::DOUBLE:
        ++doubleCount;
        break;
      case Scanner::LINENR:
                                  // Get line number,
        lineNumber = stoul(match.substr(3, match.size())) - 1;
        break;
      case Scanner::WHITESPACE:
        break;
      case Scanner::NEWLINE:
        lineNumber++;
        cout << '\n' << lineNumber << ": ";
        break;
      default:
        ++singleCharTokenCount;
        break;
    }
    tok = scanner.lex();
  }

  cout << '\n'
       << "Identifier Count: " << idCount << '\n'
       << "Integer Count: " << intCount << '\n'
       << "Doubles Count: " << doubleCount << '\n'
       << "SLC Count: " << singleCharTokenCount << '\n';
}