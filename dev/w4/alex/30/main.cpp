#include <iostream>
#include "Storage.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "specify some arguments\n";
        return 1;
    }

    // Forcibly change executable name to a.out (am using clion)
    argv[0] = new char[]{'a', '.', 'o', 'u', 't', 0};

    Storage<string> storage;

    while (*argv)
        storage.push_back(new string{*argv++});

    cout << '\n';
    cout << storage.begin()->length() << ' ' << *storage.begin() << '\n';

    sort(storage.begin(), storage.end());
    copy(storage.begin(), storage.end(), ostream_iterator<string>(cout, " "));

    cout << "\n======\n";

    sort(storage.rbegin(), storage.rend());
    copy(storage.begin(), storage.end(), ostream_iterator<string>(cout, " "));

    cout << '\n';
}