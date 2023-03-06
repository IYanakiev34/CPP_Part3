#include <iostream>
#include <vector>

#include "Expr.h"

using namespace std;
using Vect = vector<int>;

int main()
{
    Vect v1{10, 1};
    Vect v2{10, 2};

    Vect test{v1 + v2};
    /*
     * Doesn't work for > 2, probably smth wrong with my Expr since it doesn't
     * work with std::plus either.
     */

    for (int sum: test)
        cout << sum << ' ';
    cout << '\n'; // displays 20 3
}
