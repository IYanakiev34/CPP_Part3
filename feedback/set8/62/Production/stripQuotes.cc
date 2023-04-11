#include "Production.ih"
string Production::stripQuotes(string const &token) const
{
  if (token.front() == '\'')
    return string{token[1]};
  return token;
}
