#include "Parser.ih"
void Parser::showStringOrQuit(string const &value)
{
  if (value == "quit")
    quit();
  else
    showString(value);
}
