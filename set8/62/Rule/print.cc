#include "Rule.ih"

string Rule::print() const
{
  stringstream res;
  for (auto const &production : d_productions)
  {
    res << d_name << ": " << production.print();
  }
  return res.str();
}
