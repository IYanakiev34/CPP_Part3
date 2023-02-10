#include <iostream>
#include "optinsert/optinsert.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc > 1 and argv[1] == "-V"s)      // check for the -V option:
        setVerbose(cerr);                  //  it is specified, using cerr

    // ... etc. etc., remaining statements, e.g.,
    verbose() << "hello from " << argv[0] << ", called with " <<
              (argc - 1) << " arguments\n";
}