#include "main.ih"

int main()
{
  set<size_t> const universe = {1, 2, 3, 4};
  set<set<size_t>> const subsets =
    {
      {1, 2},
      {3, 4}
    };

  set<set<set<string>>> const strs =
    {
      {
        {"a", "b"},
        {"c", "c"}
      }
    };

  cout << "Universe: " << universe << '\n'
    << "subsets: " << subsets << '\n';

  cout << strs << '\n';
}