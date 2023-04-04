#include "parser.ih"

void Parser::list()
{
  for (auto const &[var, value] : d_symtab)
    cout << var << ": " << value << '\n';
  prompt();
}
