#include "main.ih"

void one()
{
    std::cout << reinterpret_cast<void *>(&negate<int>) << '\n';
}