#include "main.ih"

template<typename Type>
requires Dereferenceable<Type> Deref<Type>::Deref(Type deref)
  : d_deref(deref)
{}


int main()
{
  int var = 10;
  int *ip = &var;

  dereference1(ip);
  dereference2(ip);

  Deref{ip};
}