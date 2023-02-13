#include "OptInsert.ih"

template <typename OutputType>
OptInsert &operator<<(OptInsert&out, OutputType const &toOut)
{
  if (out.d_insert)
    out.d_out << toOut;

  return out;
}