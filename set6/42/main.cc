#include "main.ih"

int main()
{
  Scanner scanner{"test", "out"};

  vector<string> text;

  size_t token;
  while ((token = scanner.lex()))
  {
    cout << token << ' ';
    text.push_back(scanner.matched());
  }
                              // Output string that resulted in tokens
  cout << '\n';
  copy(text.begin(), text.end(), ostream_iterator<string>(cout, " "));
}