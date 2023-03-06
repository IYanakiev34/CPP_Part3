#ifndef SET4_STORAGE_H
#define SET4_STORAGE_H

#include "../Iterator/Iterator.h"

#include <vector>

template <typename Data>
class Storage
{
  std::vector<Data *> d_storage;  // store the pointers to the data
  public:
    using iterator = Iterator<Data, std::vector>;
    using reverse_iterator = std::reverse_iterator<iterator>;

    void push_back(Data *data);

    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
};
#endif //SET4_STORAGE_H
