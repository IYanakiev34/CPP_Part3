//#define XERR
#include "main.ih"

int main(int argc, char **argv)
{
  Scanner scanner{"test", "out"};

  scanner.showLine();                 // details of the 1st line

  while (scanner.lex() != 0)
    scanner.showLine();             // details of other lines
}
