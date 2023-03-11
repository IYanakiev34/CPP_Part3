#include "main.ih"

int main()
{
  int var = 1;
  int *ip = &var;
  int &ilr = var;
  int &&irr = 2;

  cout << Trait<decltype(var)>::value << '\n'
    << Trait<decltype(ip)>::value << '\n'
    << Trait<decltype(ilr)>::value << '\n'
    << Trait<decltype(irr)>::value << '\n';

  auto ptr = makeConstPtr(var);

  int plain = 3;
  ptr = &plain;
  cout << *ptr;
}