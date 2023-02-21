#include <iostream>
#include <algorithm>
#include "Data.h"
#include <iterator>

#include <vector>
#include <sstream>

int main()
{
    Data my_data;

    // Create some dummy lines in an input stream
    std::stringstream input;
    input << "This is a test\n";
    input << "This is another test\n";
    input << "This is a third test\n";

    std::copy(std::istream_iterator<std::string>(input),
              std::istream_iterator<std::string>(),
              std::back_inserter(my_data));

    my_data.display();
}
