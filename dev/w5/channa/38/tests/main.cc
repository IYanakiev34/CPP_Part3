#include "main.ih"

#include "../BasicMath/BasicMath.h"

template <typename Lhs, typename Rhs>
  requires BasicMath<Lhs, Rhs>
struct Add
{
  static void operation(Lhs lhs, Rhs rhs);
};

template <typename Lhs, typename Rhs>
  requires BasicMath<Lhs, Rhs>
void Add<Lhs, Rhs>::operation(Lhs lhs, Rhs rhs)
{
  std::cout << (lhs + rhs) << ' ';
}

template <template <typename, typename> class Operation, typename Last>
void math(Last last)
{};

template <template <typename, typename> class Operation, typename ...Args>
void math(Args &&...args);

template <
  template <typename, typename> class Operation,
  typename First, typename Second, typename ...Rest
>
void math(First first, Second second, Rest &&...rest)
{
  Operation<First, Second>::operation(first, second);
  math<Operation>(first, rest...);
}

int main()
{
  math<Add>(4,2,5,6);
//  math<Add>(4,2,"5",6); // WC: BasicMath<int, string> is false
}