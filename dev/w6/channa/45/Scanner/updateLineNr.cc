#include "Scanner.ih"

void Scanner::updateLineNr()
{
  d_lineNr = stoull(matched());
}
