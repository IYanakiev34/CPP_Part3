#include "../base.h"
#include "derived.h"

#include <vector>

#include <iostream>
using namespace std;

int main()
{
  auto var = {&Derived::nc<int, double>};

  auto var2 = {&Derived::nc_impl};

  Derived obj;
  for (auto ptr : var)
  {
    int result = (obj.*ptr)(3.14);
    cout << "result : " << result << '\n';
  }

  for (auto ptr : var2)
  {
    int result = (obj.*ptr)(3.14);
    cout << "result : " << result << '\n';
  }
}