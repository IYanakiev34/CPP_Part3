#include "main.ih"

int main()
{
    math<Add>(4, 2, 5, 6); // 6 9 10
    math<Sub>(4, 2, 5, 6); // 2 -1 -2
    math<Mul>(4, 2, 5, 6); // 8 20 24
    return 0;
}