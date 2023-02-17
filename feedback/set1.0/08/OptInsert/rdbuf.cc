#include "OptInsert.ih"

void OptInsert::rdbuf(std::streambuf *buffer)
{
  d_out.rdbuf(buffer);
                        // Before setting d_insert, make sure that the buffer
                        // is not a nullptr
  d_insert = buffer != 0;
}