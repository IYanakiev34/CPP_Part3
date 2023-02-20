#include "main.ih"

int main()
{
                        // Inside scoped block so printCounts after shows
                        // effects of destruction on non-anon objs.
  {
    Unique<int> value{ 42 };

    Unique<int> second{ value };

    Unique<string> text{ "hello world" };
    text = Unique<string>{ "hello world (2)" };

    cout << "Inside scoped block\n";
    printCounts();
  }

  cout << "\nOutside scoped block\n";
  printCounts();
}