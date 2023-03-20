#include "main.ih"

int main(int argc, char *argv[])
{
                                          // Handle edge case of argc == 1
                                          // (no file to sort specified).
                                          // Use cin, instead.
  if (argc == 1)
  {
    outputSortedStream(cin);
    return 0;
  }

                                          // If we have streams, sort each
                                          // stream
  size_t argCount = argc;
  for (size_t idx = 1; idx != argCount; ++idx)
  {
    outputWordsSorted(argv[idx]);
  }
}