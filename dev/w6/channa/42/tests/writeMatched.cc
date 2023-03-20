#include "main.ih"

void writeMatched(ostream &out, string matched, size_t token)
{
  if (matched.length() == 1)
    out << static_cast<size_t>(matched[0]);
  else
    out << token;

  out << ": " << matched << '\n';
}
