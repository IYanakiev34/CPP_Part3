#include <iostream>
#include <vector>
#include "Data.h"

using namespace std;

int main()
{
    Data data{vector<string>{"0", "1.1", "a string", "30"}};

    // returns int (30)
    int integer = data.get<int>(3);

    // returns long double (1.1)
    long double ld = data.get<long double>(1);

    // returns d_data[2] as std::string ("a string")
    string str = data.get<string>(2);

    // returns 0 since "a string" can't convert to a double
    double fails = data.get<double>(2);

    cout <<
        integer << '\n' <<
        ld << '\n' <<
        str << '\n' <<
        fails << '\n';
}
