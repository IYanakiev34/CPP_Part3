#include "main.ih"

int main(int argc, char *argv[])
{
  if (argc == 1)
    cerr << "Give source file as arg\n";

  string sourceLoc = argv[SOURCE_FILE];

  string grabbedLoc = sourceLoc;
  grabbedLoc.replace(
    sourceLoc.length() - SOURCE_EXT_LEN, sourceLoc.length(), "gsl"
  );
  string newSourceLoc = sourceLoc;
  newSourceLoc.append(".tmp");

  ofstream grabbed = ofstream{grabbedLoc};
  ofstream newSource = ofstream{newSourceLoc};

  size_t seqNum = 0;

  Scanner scanner{sourceLoc, "out"};
  size_t token;
  while ((token = scanner.lex()))
  {
    if (token != Scanner::STRING)
      newSource << scanner.matched();
    else
    {
      ++seqNum;
      newSource << "grabbed(" << seqNum << ", " << grabbedLoc << ')';
      grabbed << seqNum << ' ' << scanner.matched() << '\n';
    }
  }

//  rename(newSourceLoc, sourceLoc);


}