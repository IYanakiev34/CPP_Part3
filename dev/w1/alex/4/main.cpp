#include <iostream>
#include <vector>

template <typename Function, typename ...ParamT>
decltype(auto) forwarder(Function func, ParamT&& ...params)
{
    return func(std::forward<ParamT>(params)...);
}

using namespace std;

class Demo{
public:
    void operator()()
    {
        cout << "Hello from demo\n";
    }
};

void fun(int first, int second)
{
    cout << "First: " << first << ", Second: " << second << '\n';
}

void fun2(Demo &&dem1, Demo &&dem2)
{
    cout << "Demo1: ";
    dem1();
    cout << "Demo2: ";
    dem2();
}

// increments each argument:
void incrementer(int &one, int &two, int &three)
{
    one++;
    two++;
    three++;
}

int main()
{
    forwarder(fun, 1, 3);       // should show 'fun(1, 3)' to cout

    // fun2 expects two rvalue references
    forwarder(fun2, Demo{}, Demo{});

    forwarder(plus<string>(), "hello ", "world");

    vector<int> first;
    forwarder(                  // receives a lambda function
            [](vector<int> &first, vector<int> const &second,
               vector<int> const &third)
            {
                // modify first's elements using second's and third's
                // elements
            }, first, vector<int>{}, vector<int>{}
    );

    int x = 0;
    forwarder(incrementer, x, x, x);
    cout << x << '\n';          // should show '3'
}

