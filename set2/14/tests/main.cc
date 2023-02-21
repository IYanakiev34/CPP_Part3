#include "main.ih"

int main()
{
  Storage<std::string> storage;

  sort(storage.begin(), storage.end());
  sort(storage.rbegin(), storage.rend());
}