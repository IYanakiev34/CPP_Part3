#include "opinsert.h"

namespace 
{
    OptInsert optIns;
}

void setVerbose(std::ostream &out)
{
    optIns.rdbuf(out.rdbuf());
}

OptInsert &verbose()
{
    return optIns;
}
