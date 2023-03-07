#include "main.ih"

int main()
{
   cout << Convert<100, 2>::CP{} << '\n'    // displays '1100100'
     << Convert<57005, 8>::CP{} << '\n'    // displays '157255'
     << Convert<57005, 16>::CP{} << '\n'   // displays 'dead'
     << Convert<57005, 32>::CP{} << '\n'   // displays '1nld'
     << Convert<57005, 36>::CP{} << '\n'   // displays '17zh'
     << Convert<0, 32>::CP{} << '\n'   // displays '0'
     << Convert<0, 2>::CP{} << '\n'   // displays '0'
     << Convert<0, 36>::CP{} << '\n'   // displays '0'
     << Convert<SIZE_MAX, 2>::CP{} << '\n'   // displays 64 '1's
     << Convert<SIZE_MAX, 36>::CP{} << '\n';  // displays '3w5e11264sgsf'
}