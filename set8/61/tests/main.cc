#include "main.ih"

using namespace std;

int main(int argc, char **argv)
{
  if (argc == 1)
  {
    Parser parser{' '};
    parser.parse();
  }
  else
  {
    Parser parser{argv[1][0]};
    parser.parse();
  }


}

