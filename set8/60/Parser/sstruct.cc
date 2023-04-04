#include "parser.ih"

RuleValue::RuleValue()
:
    d_type(VARIABLE),
    d_idx(0)
{}

RuleValue::RuleValue(double value)
:
    d_type(VALUE),
    d_number(value)
{}

RuleValue::RuleValue(unsigned idx)
:
    d_type(VARIABLE),
    d_idx(idx)
{}

RuleValue::RuleValue(
  RuleValue::SingleArgFunc func,
  bool argGeometric,
  bool resGeometric
)
:
    d_type(FUNC),
    d_func(func),
    d_argGeometric(argGeometric),
    d_resGeometric(resGeometric)
{}

