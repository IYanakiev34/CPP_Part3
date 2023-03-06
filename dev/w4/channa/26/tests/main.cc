#include "main.ih"

int main()
{
  deque<string> ds = {"kilo", "lima", "mike"};
  vector<int> vi {1, 2, 3, 4, 5};

  using InsertableVector = Insertable<vector, int>;

  InsertableVector iv;
  InsertableVector iv2(vi);
  InsertableVector iv3(4);
  InsertableVector iv4(iv2);

  cout << iv2 << '\n' <<
       iv3 << '\n' <<
       iv4 << '\n';

  iv3.push_back(123);
  cout << iv3 << '\n';

  Insertable<deque, string> sd(ds);
  sd.push_back("november");

  cout << "sd has " << sd.size() << " elements and contains:\n"
       << sd << '\n';

}

