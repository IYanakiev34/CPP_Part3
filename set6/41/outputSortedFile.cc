#include "main.ih"

                                      // Given a file, this function sorts the
                                      // words in it and outputs them to
                                      // cout
void outputSortedFile(string const &streamName)
{
  ifstream currStream = ifstream{streamName};
  outputSortedStream(currStream);
  cout << '\n';

}
