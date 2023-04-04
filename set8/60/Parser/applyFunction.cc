#include "parser.ih"

RuleValue Parser::applyFunction(
  RuleValue const &func, RuleValue const &value
) const
{
  double arg = value.d_number;
  if (func.argGeometric())
    arg = toRad(arg);

  double res = func.d_func(arg);

  if (func.resGeometric())
    res = toCurrentAngleUnit(res);

  return RuleValue(res);
}
