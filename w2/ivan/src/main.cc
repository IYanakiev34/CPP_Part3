#include <iostream>

// Exercise 9
// #include "Unique.h"

// Exercise 10
// #include "Unique2.h"

// Exercise 11
// #include "Unique3.h"

// Exercise 12
// #include "simple.h"

// Exercise 14
// #include "14/storage.h"
// #include <algorithm>
// #include <vector>
// #include <functional>
// #include <iterator>

// Exercise 15
#include "15/base.h"

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
    /*
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
    */

    // 12
    /*
    Simple<int> sim1;
    std::cout << sim1.get() << '\n';
    int val = 12;
    Simple<int *> sim2{&val};
    std::cout << sim2.get() << '\n';
    */

    // 14
    // not sure if it works
    /*
    auto *ivan = new std::string{"ivan"};
    auto *alex = new std::string{"alex"};
    auto *channa = new std::string{"channa"};

    std::vector<std::string *> data{ivan, alex, channa};
    Storage<std::string> storage{data};
    */

    // 15

    using FuncPtr = int (Derived::*)(double);
    FuncPtr arr[] = {&Derived::nc};

    Derived obj;
    for (auto ptr : arr)
    {
        int result = (obj.*ptr)(3.14);
        std::cout << "result: " << result << std::endl;
    }

    return 0;
}
