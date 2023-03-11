#include "main.ih"

#include<vector>

int main()
{

  Data data;

  decltype(auto) res = data.get<unsigned long long>(1);

  cout << res << '\n';

}