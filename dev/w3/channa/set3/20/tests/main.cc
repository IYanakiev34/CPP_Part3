#include "main.ih"

int main()
{
  cout << Merge
    <
      Chars<'1', '2', '3'>,
      Merge
      <
        Chars<'4', '5'>,
        OneChar<'6'>
      >::CP
    >
  ::CP{} << '\n';
}