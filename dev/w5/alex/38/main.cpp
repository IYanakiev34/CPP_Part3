#include <iostream>
#include <string>

template<typename Lhs, typename Rhs>
concept BasicMathable =
requires(Lhs lhs, Rhs rhs)
{
    lhs + rhs;
    lhs - rhs;
    lhs * rhs;
    lhs / rhs;
    rhs + lhs;
    rhs - lhs;
    rhs * lhs;
    rhs / lhs;
    -lhs;
    -rhs;
};

template<typename Lhs, typename Rhs>
requires BasicMathable<Lhs, Rhs>
struct Add
{
    inline static void operation(Lhs lhs, Rhs rhs)
    {
        std::cout << (lhs + rhs) << ' ';
    }
};

template<typename Lhs, typename Rhs>
requires BasicMathable<Lhs, Rhs>
struct Sub
{
    inline static void operation(Lhs lhs, Rhs rhs)
    {
        std::cout << (lhs - rhs) << ' ';
    }
};

#define OpType template<typename, typename> class

template<OpType Operation, typename ...Args>
void math();

// Base case
template<OpType Operation, typename FirstOnly>
void math(FirstOnly first)
{
    std::cout << '\n';
}

template<OpType Operation, typename First, typename Second, typename ...Rest>
void math(First first, Second second, Rest ...rest)
{
    Operation<First, Second>::operation(first, second);
    math<Operation>(first, rest...);
}

using namespace std;

int main()
{
    math<Add>(4, 2, 5, 6);      // shows: 6  9 10
    math<Sub>(4, 2, 5, 6);      // shows: 2 -1 -2
    //math<Add>(4, 2, "5"s, 6); // WC: constraint not satisfied.
}
