#include "main.ih"
int main(int argc, char **argv)
{
  Storage<std::string> storage;

  while (*argv)
    storage.push_back(new string{ *argv++ });

  sort(storage.begin(), storage.end());
  sort(storage.rbegin(), storage.rend());
}
