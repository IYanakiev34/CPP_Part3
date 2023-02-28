#include <iostream>
#include "../Unique/Unique.h"

using namespace std;

int main()
{
  {
    Unique<int> integral;
    Unique<float> floating;
    cout << Counter::getActual() << '\n';
    cout << Counter::getGlobal() << '\n';
    cout << Unique<int>::actual() << '\n';
    cout << Unique<int>::count() << '\n';
  }
    Unique<int> integral;
    Unique<float> floating;
    cout << Counter::getActual() << '\n';
    cout << Counter::getGlobal() << '\n';
    cout << Unique<int>::actual() << '\n';
    cout << Unique<int>::count() << '\n';
}
