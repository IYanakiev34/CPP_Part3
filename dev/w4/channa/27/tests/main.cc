#include "main.ih"

#include<vector>

int main()
{

  Data data;

  decltype(auto) res = data.get<long long>(1);

  cout << res << '\n';

}