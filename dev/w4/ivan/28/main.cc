#include "Trait/Trait.h"
#include <iostream>

#include <vector>

// TODO function for type traits

int main()
{
    int x = 5;
    int *ptr = &x;
    int &ref = x;
    int &&rvalref = 5;

    std::cout << TypeTrait<int>::value << std::endl;    // 1
    std::cout << TypeTrait<int *>::value << std::endl;  // 2
    std::cout << TypeTrait<int &>::value << std::endl;  // 3
    std::cout << TypeTrait<int &&>::value << std::endl; // 4

    // I dont get the function template thing

    std::vector<int> vi;
    vi.push_back(10);
    return 0;
}