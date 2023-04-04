#include "parser.ih"

RuleValue Parser::constant()
{
  return {
    RuleValue::d_constantMap[d_scanner.matched()]
  };
}
