#include "main.ih"

int main()
{
                  // Showing how we use NrTrait / how we show the traits of
                  // 1871862 to stdout via a single cout statement.
  cout << NrTrait<1971962>::value << '\n'
    << NrTrait<1971962>::even << '\n'
    << NrTrait<1971962>::by3 << '\n'
    << NrTrait<1971962>::width << '\n';

}