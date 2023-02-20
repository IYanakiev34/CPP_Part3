#include "main.ih"

// Hard coded to print int / string counts, as this is
// just for demo. Would be TC (for a demo)
// to make this general.
void printCounts()
{
  cout << "int count: " << Unique<int>::count() << ", ";
  cout << "int actual: " << Unique<int>::actual() << '\n';

  cout << "string count: " << Unique<string>::count() << ", ";
  cout << "string actual: " << Unique<string>::actual() << '\n';
}
