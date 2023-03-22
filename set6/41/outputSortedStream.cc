#include "main.ih"

                                          // Output a sorted list of words
                                          // gathered from a stream to cout
void outputSortedStream(istream &in)
{
  vector<string> sorted;
                                  // Get words in file
  Scanner scanner{in};
  while(scanner.lex())
    sorted.push_back(scanner.matched());

                                // sort and output file
  sort(sorted.begin(), sorted.end());
  copy(sorted.begin(), sorted.end(), ostream_iterator<string>(cout, " "));
}
