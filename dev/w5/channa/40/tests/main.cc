#include "main.ih"

int main(int argc, char **argv)
{
  Storage<std::string> storage;

  while (*argv)
    storage.push_back(new string{ *argv++ });

  sort(storage.begin(), storage.end());
  copy(storage.begin(), storage.end(), ostream_iterator<string>(cout, " "));
  cout << '\n';

  sort(storage.rbegin(), storage.rend());
  copy(storage.begin(), storage.end(), ostream_iterator<string>(cout, " "));
}
