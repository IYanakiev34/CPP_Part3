#include "Counter.h"

Counter::~Counter()
{
    --s_actualCount;
}