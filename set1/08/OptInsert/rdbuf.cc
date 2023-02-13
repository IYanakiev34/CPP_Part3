#include "OptInsert.ih"

void OptInsert::rdbuf(std::streambuf *buffer)
{
  d_out.rdbuf(buffer);
  d_insert = buffer != 0;
}