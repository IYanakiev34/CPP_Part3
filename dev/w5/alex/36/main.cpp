#include <iostream>

template <typename Lhs, typename Rhs>
concept Comparable =
        requires(Lhs lhs, Rhs rhs)
        {
            lhs == rhs;
            lhs < rhs;
            lhs > rhs;
        };

template <typename Lhs, typename Rhs>
requires Comparable<Lhs, Rhs>
int compare(Lhs lhs, Rhs rhs)
{
    if (lhs == rhs)
        return 0;
    if (lhs < rhs)
        return -1;
    return 1;
}

template <typename Type>
requires Comparable<Type, Type>
class Compare
{
};

int main()
{
    // work
    compare(1, 1.0);
    Compare<int> compareWorks;

    // do not work
    compare(1, std::string{"1"});
    Compare<std::ostream> compareFails;
}
