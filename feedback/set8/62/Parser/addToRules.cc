#include "Parser.ih"
Rules &Parser::addToRules(Rule const &rule)
{
  d_rules.add(rule);
  return d_rules;
}
