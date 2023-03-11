#include "main.ih"
                                // Demo Deref, dereference1, dereference2
int main()
{
  int var = 10;
  int *ip = &var;

  dereference1(ip);
  dereference2(ip);

  Deref{ip};
}