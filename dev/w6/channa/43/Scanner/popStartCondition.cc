#include "Scanner.ih"

                              // Taken from flexc++ manual
void Scanner::popStartCondition()
{
  begin(d_scStack.top());
  d_scStack.pop();
}
