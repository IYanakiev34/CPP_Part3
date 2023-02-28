#include "Counter.ih"

Counter::~Counter()
{
  --s_actualCount;
}