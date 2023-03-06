#include "main.ih"

int main()
{
  tuple<int, double> t1{ 1, 12.5 };

  TupleMod< tuple<int, double> > tmod(t1);

  auto t2 = t1 + t1;
  cout << tuple_size< decltype(t2) >::value << '\n';  // shows 4

  auto t3 = tmod.add(12);
  cout << tuple_size< decltype(t3) >::value << '\n';  // shows 3

}