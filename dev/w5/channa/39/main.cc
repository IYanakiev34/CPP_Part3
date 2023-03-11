#include "main.ih"

                        // Demo to show the use of the RndIterator concept
int main()
{
  vector<int> vi{1,2,3,4,3,2,1};

  sortWithConcepts(vi.begin(), vi.end());
}