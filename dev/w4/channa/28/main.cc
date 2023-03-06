#include "main.ih"

// TODO: Move to its own file
template <typename Type>
int const *func(Type var)
{
  return 0;
}

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