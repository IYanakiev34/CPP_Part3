#include "opinsert.h"
#include <iostream>
#include <string>

int main (int argc, char **argv)
{

    if (argc > 1 and std::string{argv[1]} == std::string{"-V"})
        setVerbose(std::cerr);

    verbose() << "hello from " << argv[0] << ", called with " << (argc-1)
        << " arguments\n";
    return 0;
}
