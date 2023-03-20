#include "main.ih"

                                      // Given a file, this function sorts the
                                      // words in it and outputs them to
                                      // cout
void outputWordsSorted(string const &streamName)
{
  cout << "Sorting: " << streamName << '\n';
  ifstream currStream = ifstream{streamName};
  outputSortedStream(currStream);
  cout << '\n';

}
