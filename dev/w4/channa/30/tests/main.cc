#include "main.ih"

int main(int argc, char **argv)
{
  if (argc == 1)
  {
    cout << "specify some arguments\n";
    return 1;
  }

  Storage<string> storage;

  while (*argv)
    storage.push_back(new string{ *argv++ });

  cout << '\n';
  cout << storage.begin()->length() << ' ' << *storage.begin() << '\n';

  sort(storage.begin(), storage.end());
  copy(storage.begin(), storage.end(), ostream_iterator<string>(cout, " "));

  cout << "\n======\n";

  sort(storage.rbegin(), storage.rend());
  copy(storage.begin(), storage.end(), ostream_iterator<string>(cout, " "));

  cout << '\n';
}