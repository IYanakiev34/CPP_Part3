#include "main.ih"

                                // Takes in words from an input stream (or a
                                // number of files specified in the arguments)
                                // and outputs a sorted list of the words.
int main(int argc, char *argv[])
{
                                // Handle edge case of no file to sort specified
  size_t argCount = argc;
  if (argc == 1)
    outputSortedStream(cin);
  else
    for (size_t idx = 1; idx != argCount; ++idx)
                                // If we have streams, sort each stream
                                // Each stream results in a space separated list
                                // Lists are spearated by new lines
      outputSortedFile(argv[idx]);
}