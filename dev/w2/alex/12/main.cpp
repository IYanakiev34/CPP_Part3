#include <iostream>
#include "simple.h"

template <typename Ptr>     // Ptr could be an int *, string *, etc.
void fun(Ptr ptr)
{
    Simple<Ptr> s1(ptr);    // (1) ??
    Simple<Ptr> s2(*ptr);   // (2) ??
}

using namespace std;

int main(int argc, char **argv)
{
    int *test = new int;
    fun(test);

    Simple<int> sim1;
    cout << sim1.get() << '\n';
    int val = 12;
    Simple<int *> sim2{ &val };
    cout << sim2.get() << '\n';
}