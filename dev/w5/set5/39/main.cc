#include "main.ih"

template <RndIterator RAI>
void sortWithConcepts(RAI first, RAI last)
{
  std::sort(first, last);
}

int main()
{
  vector<int> vi{1,2,3,4,3,2,1};

  sortWithConcepts(vi.begin(), vi.end());
}