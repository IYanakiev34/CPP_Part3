#include <iostream>

template <typename Lhs, typename Rhs>
concept BasicMath =
    requires(Lhs lhs, Rhs rhs)
    {
        lhs + rhs;
        lhs - rhs;
        lhs * rhs;
        lhs / rhs;
        -lhs;
        -rhs;
    };

template <typename Lhs, typename Rhs>
    requires BasicMath<Lhs, Rhs>
void simpleMath(Lhs lhs, Rhs rhs)
{
}

int main()
{
    // Valid
    simpleMath(3.4, 5);

    // Not valid "candidate template ignored: constraints not satisfied
    // because BasicMath<int, std::basic_str<char>> evaluated to false"
    simpleMath(6, std::string{"7"});
}
