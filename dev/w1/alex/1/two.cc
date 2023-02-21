#include "main.ih"

void two()
{
    std::cout << reinterpret_cast<void *>(&negate<int>) << '\n';
}