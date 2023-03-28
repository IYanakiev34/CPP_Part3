#include "Scanner.ih"
                              // Taken from flexc++ manual
void Scanner::push(StartCondition_ next)
{
  d_scStack.push(startCondition());
  begin(next);
}
