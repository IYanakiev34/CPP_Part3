#ifndef SET5_NORMALITERATOR_H
#define SET5_NORMALITERATOR_H

#include <concepts>

                        // Forward declare Storage to compare against it's
                        // iterator type
template <typename Data>
class Storage;

                        // Used for free operators of Storage<Data>::iterator
                        // Prevents binding to any other iterator (such as the
                        // reverse iterator)
template <typename Iterator>
concept NormalIter =
  std::same_as<
    Iterator,
                        // Iterator must be the same iterator as in Storage
    typename Storage<typename Iterator::value_type>::iterator
  >;

#endif //SET5_NORMALITERATOR_H
