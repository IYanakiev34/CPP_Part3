#include "Counter.h"

Counter::Counter()
{
    ++s_globalCount;
    ++s_actualCount;
}