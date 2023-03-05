#include <iostream>
#include <vector>
#include "Insertable.h"

using InsertableVector = Insertable<std::vector, int>;
using namespace std;

int main()
{
    vector<int> vi {1, 2, 3, 4, 5};
    InsertableVector iv;
    InsertableVector iv2(vi);
    InsertableVector iv3(4);
    InsertableVector iv4(iv2);
    cout << iv2 << '\n' <<
            iv3 << '\n' <<
            iv4 << '\n';
    iv3.push_back(123);
    cout << iv3 << '\n';
}
        