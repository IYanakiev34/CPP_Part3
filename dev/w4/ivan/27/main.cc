#include <iostream>
#include <string>

template <typename Type>
struct GetReturnValue
{
    enum
    {
        integral = (1 + (T)0.5 = 1.0),
        floating = (1 + (T)0.5 = 1.5),
        string = 0
    };
};

template <>
struct GetReturnValue<std::string>
{
    enum
    {
        integral = 0,
        floating = 0,
        string = 1,
    };
};

int main()
{

    return 0;
}