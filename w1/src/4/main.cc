#include <iostream>
#include <utility>
#include <vector>

struct Demo
{

    void operator()()
    {
        std::cout << "Hello from demo\n";
    }
};

void fun(int i, int p)
{
    std::cout << "i: " << i << ", p: " << p << "\n";
}

void fun2(Demo&& dm,Demo &&dm2)
{
    std::cout << "Dm 1: ";
    dm();
    std::cout << "\n";
    std::cout << "Dm 2: ";
    dm2();
    std::cout << "\n";
};


template <typename Function, typename ...Params>
decltype(auto) forwarder(Function func, Params&&... params)
{
    return func(std::forward<Params>(params)...);
}


int main(int argc, char **argv)
{
    
    forwarder(fun,1,3);

    forwarder(fun2,Demo{},Demo{});

    std::vector<int> first;
        forwarder(                  // receives a lambda function
            [](std::vector<int> &first, std::vector<int> const &second, 
                                    std::vector<int> const &third)
            {
                // modify first's elements using second's and third's
                // elements
                std::cout << "mod\n";
            }, first, std::vector<int>{}, std::vector<int>{}
        );

    return 0;
}
