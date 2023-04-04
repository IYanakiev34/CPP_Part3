#include "Scanner.ih"
Scanner::Scanner(char sep, std::string const &infile, std::string const &outfile, bool keepCwd)
  :
  ScannerBase(infile, outfile, keepCwd),
  d_sep(sep)
{}
