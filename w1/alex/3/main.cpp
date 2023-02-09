#include <iostream>
#include <string>

template <typename T>
inline T *rawCapacity(std::size_t capacity)
{
    return static_cast<T *>(operator new(capacity * sizeof(T)));
}

using namespace std;

int main()
{
    size_t const arrSize = 10;
    auto *buf = rawCapacity<string>(arrSize);
    new (buf + 4) string{"This is what I want to print.\n"};
    cout << buf[4];
    buf[4].~string(); // must manually dealloc
    operator delete(buf);
}
