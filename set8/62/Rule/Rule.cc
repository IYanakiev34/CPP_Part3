#include "Rule.ih"
Rule::Rule(string const &name, vector<Production> const &productions)
  : d_name(name),
    d_productions(productions)
{
}
