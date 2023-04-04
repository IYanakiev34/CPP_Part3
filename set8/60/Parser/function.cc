#include "parser.ih"

RuleValue Parser::function()
{
  std::string const &funcName = d_scanner.matched();
  bool argGeo = false;
  bool resGeo = false;

  if (
    find(d_argGeoFuncs.begin(), d_argGeoFuncs.end(), funcName)
    != d_argGeoFuncs.end()
  )
    argGeo = true;

  if (
    find(d_resGeoFuncs.begin(), d_resGeoFuncs.end(), funcName)
    != d_resGeoFuncs.end()
    )
    resGeo = true;

  return {RuleValue::d_functionMap[d_scanner.matched()], argGeo, resGeo};
}
