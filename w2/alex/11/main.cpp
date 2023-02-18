#include <iostream>
#include "Unique.h"

using namespace std;

int main()
{
    Unique<int> integral;
    Unique<float> floating;
    cout << Unique<int>::globalActual() << '\n';
}
