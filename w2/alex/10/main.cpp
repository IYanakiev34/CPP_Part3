#include <iostream>
#include "Unique.h"

using namespace std;

inline void display(int count, int actual)
{
    cout << "Expect " << count << ", " << actual
         << " Actual " << Unique<int>::count() << ", "
         << Unique<int>::actual() << '\n';
}

int main()
{
    Unique<int> def;
    display(1, 1);
    Unique<int> val{1};
    display(2, 2);
    int *a = new int;
    Unique<int> ptr{a};
    display(3, 3);
    Unique<int> move{std::move(def)};
    display(4, 3);
    Unique<int> copy{move};
    display(5, 4);
    Unique<int> moveAssigned = std::move(copy);
    display(6, 4);
    Unique<int> copyAssigned = moveAssigned;
    display(7, 5);
}
