#include "optinsert.ih"

namespace
{
    OptInsert optInsert;
}

void setVerbose(std::ostream &out)
{
    optInsert.rdbuf(out.rdbuf());
}

OptInsert &verbose()
{
    return optInsert;
}