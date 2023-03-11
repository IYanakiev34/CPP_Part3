#include "main.ih"

template <typename Lhs, typename Rhs>
    requires BasicMath<Lhs, Rhs>
void Math(Lhs const &lhs, Rhs const &rhs)
{
}

int main()
{
    Math(1, 5.f);
    Math(4, std::string{"hello"});
}