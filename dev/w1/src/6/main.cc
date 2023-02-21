#include "exception/exception.h"
#include <iostream>
#include <exception>

using namespace std;

int main (int argc, char **argv)
{
    std::string const name{"Ivan"};
    try
    {
        throw Exception{} << "insert anything that's "
                "ostream-insertable: " << "strings"s << ", values " <<
                argc << " etc., etc." << name;
    }
    catch (exception const &ex)
    {
        cout << ex.what() << '\n';
    } 
    return 0;
}
