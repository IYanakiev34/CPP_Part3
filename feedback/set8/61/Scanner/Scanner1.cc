#include "Scanner.ih"

Scanner::Scanner(char sep, std::istream &in, std::ostream &out, bool keepCwd)
  :
  ScannerBase(in, out, keepCwd),
  d_sep(sep)
{}
