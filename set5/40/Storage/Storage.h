#ifndef SET4_STORAGE_H
#define SET4_STORAGE_H

#include "NormalIterator.h"

#include <vector>

                                      // Free operator declarations for Storage
                                      // to reference as friends.
int operator-(NormalIter auto const &lhs, NormalIter auto const &rhs);
bool operator==(NormalIter auto const &lhs, NormalIter auto const &rhs);
auto operator<=>(NormalIter auto const &lhs, NormalIter auto const &rhs);
auto operator+(NormalIter auto const &lhs, int step);

template <typename Data>
class Storage
{
  std::vector<Data *> d_storage;

  public:
                                            // Iterators for d_storage
    struct iterator;
    using reverse_iterator = std::reverse_iterator<iterator>;

                                            // Add to d_storage
    void push_back(Data *data);
                                            // Get iterators for d_storage
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
};

#include "Iterator.f"
#include "StorageImpl.f"
#include "IteratorImpl.f"
#include "IteratorFreeOpImpl.f"

#endif //SET4_STORAGE_H
