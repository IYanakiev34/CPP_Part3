#include "Rules.ih"
string Rules::print() const
{
  stringstream res;
  for (auto const &rule : d_rules)
    res << rule.print() << '\n';

  return res.str();
}
