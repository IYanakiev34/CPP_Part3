#include "Counter.ih"

Counter::Counter()
{
  ++s_globalCount;
  ++s_actualCount;
}