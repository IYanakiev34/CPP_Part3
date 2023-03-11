#include "main.ih"

int main()
{
  basicMathTest(1, 2); // Compiles
//  basicMathTest(1, "BasicMathTest"s);  // WC: int, string doesn't satisfy
                                          // BasicMath
}