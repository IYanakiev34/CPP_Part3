#include "parser.ih"

RuleValue::FunctionMap RuleValue::d_functionMap =
{
  {"exp", exp},
  {"ln", log},
  {"sin", sin},
  {"asin", asin},
  {"sqrt", sqrt},
  {"abs", abs}
};

std::vector<std::string> Parser::d_argGeoFuncs =
  {
    "sin"
  };

std::vector<std::string> Parser::d_resGeoFuncs =
  {
    "asin"
  };

Parser::StrToAngleMode Parser::d_strToAngleMode =
{
  {"rad", Parser::AngleMode::RAD},
  {"deg", Parser::AngleMode::DEG},
  {"grad", Parser::AngleMode::GRAD},
};

RuleValue::ConstantMap RuleValue::d_constantMap =
{
  {"e", numbers::e},
  {"pi", numbers::pi}
};