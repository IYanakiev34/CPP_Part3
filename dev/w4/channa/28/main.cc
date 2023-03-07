#include "main.ih"

int main()
{
  int var = 1;
  int *ip = &var;
  int &ilr = var;
  int &&irr = 2;

  cout << Trait<decltype(var)>::value
    << Trait<decltype(ip)>::value
    << Trait<decltype(ilr)>::value
    << Trait<decltype(irr)>::value;

  auto ptr = func(var);
  ptr = &var;
  cout << *ptr;
}