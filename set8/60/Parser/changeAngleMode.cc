#include "parser.ih"

void Parser::changeAngleMode()
{
  d_angleMode = d_strToAngleMode[d_scanner.matched()];
  prompt();
}