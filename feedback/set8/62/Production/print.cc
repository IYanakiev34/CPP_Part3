#include "Production.ih"
string Production::print() const
{
  stringstream res;
  for (auto const &token : d_tokens)
    res << stripQuotes(token) << ' ';

  return res.str();
}
