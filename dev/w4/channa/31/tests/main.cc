#include <vector>
#include <iostream>

using namespace std;

class VI : public std::vector<int>
{};

operator+(VI const &v1, VI const &v2)
{

}

int main()
{
  using VI = std::vector<int>;

  VI v1 = {1,2,3,4,5};
  VI v2{v1};
  VI v3{v1};
  VI v4{v1};

  cout << v1 + v2 + v3 + v4;
}