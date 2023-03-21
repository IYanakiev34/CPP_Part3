#include "main.ih"

int main(int argc, char *argv[])
{
                                // Handle edge case of no file to sort specified
  size_t argCount = argc;
  if (argc == 1)
    outputSortedStream(cin);
  else
    for (size_t idx = 1; idx != argCount; ++idx)
                                // If we have streams, sort each stream
      outputSortedFile(argv[idx]);
}