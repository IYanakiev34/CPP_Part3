#include "Counter.ih"

std::size_t Counter::getGlobal()
{
  return s_globalCount;
}
