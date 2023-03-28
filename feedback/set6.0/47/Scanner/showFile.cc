#include "Scanner.ih"

void Scanner::showLine()
{
  size_t offset = lineOffset();
  std::cout << "line " << lineNr() << " at offset " << "0x" << std::hex <<
            offset << " (" << std::dec << offset << ")\n";
}
