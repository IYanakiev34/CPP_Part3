#include "main.ih"

int main()
{
  Data data;
  copy(
    istream_iterator<string>(cin), istream_iterator<string>(),
    back_inserter(data)
  );
}