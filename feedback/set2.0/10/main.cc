#include "Unique2.h" //JB: FIRST (IY : fixed it)
#include <iostream>

int main()
{
    Unique<int> value{42};
    Unique<int> second{value};

    std::cout << value.get() << " " << second.get() << "\n";
    second.get() = 13;

    std::cout << value.get() << " " << second.get() << "\n";

    {
        Unique<std::string> text{"hello world"};
        text = Unique<std::string>{"hello world(2)"};

        std::cout << text.get() << "\n";
        // JB: CTR
        std::cout << "Count strings: " << Unique<std::string>::s_count
                  << ", Actual: " << Unique<std::string>::s_actual << "\n";
    }
    std::cout << "Count strings: " << Unique<std::string>::s_count
              << ", Actual: " << Unique<std::string>::s_actual << "\n";

    std::cout << "Count int: " << Unique<int>::s_count << ", Actual: "
              << Unique<int>::s_actual << "\n";
}
