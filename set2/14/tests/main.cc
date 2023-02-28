#include "main.ih"

int main()
{
  Storage<std::string> storage;

  sort(storage.begin(), storage.end());
  sort(storage.rbegin(), storage.rend());

  for (auto it = storage.rbegin(); it != storage.rend(); ++it);
}