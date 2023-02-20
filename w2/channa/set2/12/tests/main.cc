#include "main.ih"

template <typename Ptr>
void fun(Ptr ptr)
{
  Simple<Ptr> s1(ptr);
  Simple<Ptr> s2(*ptr);
}

int main()
{
  Simple<int> sim1;

  cout << sim1.get() << '\n';

  int val = 12;

  Simple<int *> sim2{ &val };

  cout << sim2.get() << '\n';

  fun(&val);
}