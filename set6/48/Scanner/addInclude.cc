#include "Scanner.ih"

void Scanner::addInclude()
{
  std::string match = matched();
  std::string inc = match.substr(10, match.size() - 11);

  auto iter = d_includes.find(inc);
  if (iter != d_includes.end())
  {
    throw "Error: recursive inclusion of file: " + inc;
  }

  try
  {
    pushStream(inc);
  }
  catch (std::exception &exec)
  {
    throw inc + " does not exist";
  }
}
