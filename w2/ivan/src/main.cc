#include <iostream>

// Exercise 9
// #include "Unique.h"

// Exercise 10
// #include "Unique2.h"

// Exercise 11
#include "Unique3.h"

int main(int argc, char **argv)
{
    // 9
    /*
    Unique<int> value{42};
    Unique<int> second{value};

    std::cout << value.get() << " " << second.get() << "\n";
    second.get() = 13;

    std::cout << value.get() << " " << second.get() << "\n";

    Unique<std::string> text{"hello world"};
    text = Unique<std::string>{"hello world(2)"};

    std::cout << text.get() << "\n";
    */

    // 10
    /*
    Unique<int> value{42};
    Unique<int> second{value};

    std::cout << value.get() << " " << second.get() << "\n";
    second.get() = 13;

    std::cout << value.get() << " " << second.get() << "\n";

    {
        Unique<std::string> text{"hello world"};
        text = Unique<std::string>{"hello world(2)"};

        std::cout << text.get() << "\n";
        std::cout << "Count strings: " << Unique<std::string>::s_count
                  << ", Actual: " << Unique<std::string>::s_actual << "\n";
    }
    std::cout << "Count strings: " << Unique<std::string>::s_count
              << ", Actual: " << Unique<std::string>::s_actual << "\n";

    std::cout << "Count int: " << Unique<int>::s_count << ", Actual: "
              << Unique<int>::s_actual << "\n";
    */

    // 11
    Unique<int> value{42};
    Unique<int> second{value};

    std::cout << value.get() << ' ' << second.get() << '\n';
    second.get() = 13;

    std::cout << value.get() << ' ' << second.get() << '\n';

    {
        Unique<std::string> text{"hello world"};
        text = Unique<std::string>{"hello world(2)"};

        std::cout << text.get() << '\n';
        std::cout << "Count strings: " << Unique<std::string>::s_count
                  << ", Actual: " << Unique<std::string>::s_actual << '\n';
        std::cout << "Global count: " << Unique<std::string>::getGlobalCount()
                  << ", Actual: " << Unique<std::string>::getGlobalActual() << '\n';
    }
    std::cout << "Count strings: " << Unique<std::string>::s_count
              << ", Actual: " << Unique<std::string>::s_actual << '\n';

    std::cout
        << "Count int: " << Unique<int>::s_count << ", Actual: "
        << Unique<int>::s_actual << '\n';

    std::cout << "Global count: " << Unique<std::string>::getGlobalCount()
              << ", Actual: " << Unique<std::string>::getGlobalActual() << '\n';
    return 0;
}
