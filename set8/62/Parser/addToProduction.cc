#include "Parser.ih"
Production &Parser::addToProduction(Production &production)
{
  production.add(d_scanner.matched());
  return production;
}
