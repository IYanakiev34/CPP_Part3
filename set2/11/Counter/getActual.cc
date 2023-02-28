#include "Counter.ih"

std::size_t Counter::getActual()
{
  return s_actualCount;
}