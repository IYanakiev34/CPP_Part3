#include "OptInsert.ih"

                      // These functions have to be in one file, to access
                      // anonymous namespace optInsert

namespace
{
  OptInsert optInsert;
}

                      // Sets out via setting the rdbuf of d_out
void setVerbose(ostream &out)
{
  optInsert.rdbuf(out.rdbuf());
}

                      // Returns instantiated optInsert
OptInsert &verbose()
{
  return optInsert;
}