#include "main.ih"

int main()
{
  math<Add>(4,2,5,6);
//  math<Add>(4,2,"5",6); // WC: BasicMath<int, string> is false
}