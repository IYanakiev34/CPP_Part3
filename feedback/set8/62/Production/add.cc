#include "Production.ih"
void Production::add(string const &token)
{
  d_tokens.push_back(token);
}
