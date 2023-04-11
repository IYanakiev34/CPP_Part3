#include "Parser.ih"
std::vector<Production> &Parser::addToProductions(
  std::vector<Production> &productions, Production const &production
)
{
  productions.push_back(production);
  return productions;
}
