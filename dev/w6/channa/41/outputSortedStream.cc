#include "main.ih"

                                          // Output a sorted list of words
                                          // gathered from a stream
void outputSortedStream(istream &in)
{
  vector<string> sorted = sortWordsFromStream(in);
  copy(sorted.begin(), sorted.end(), ostream_iterator<string>(cout, " "));
}
