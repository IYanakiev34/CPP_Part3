#include <iostream>
#include "Storage.h"

using namespace std;

int main()
{
    auto *one = new string{"one"};
    auto *two = new string{"two"};
    auto *three = new string{"three"};
    vector<string *> strings{one, two, three};
    Storage<string> storage{strings};

    sort(storage.begin(), storage.end());
    for (auto & it : storage)
    {
        cout << it << '\n';
    }

    sort(storage.rbegin(), storage.rend());
    for (auto & it : storage)
    {
        cout << it << '\n';
    }

}
