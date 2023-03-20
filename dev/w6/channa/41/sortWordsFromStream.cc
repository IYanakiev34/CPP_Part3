#include "main.ih"
                              // Gets words from a stream and sorts
                              // it returns a vector of the sorted
                              // words
vector<string> sortWordsFromStream(istream &in)
{
  vector<string> words;
                                // Get words from stream and put into
                                // words
  Scanner scanner{in};
  while(scanner.lex())
    words.push_back(scanner.matched());

  sort(words.begin(), words.end());
  return words;
}
