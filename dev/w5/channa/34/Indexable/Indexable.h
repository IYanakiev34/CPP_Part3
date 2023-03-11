#ifndef SET5_INDEXABLE_H
#define SET5_INDEXABLE_H

#include <concepts>

                                // This concept ensures that a template type
                                // is indexable and returns a reference
                                // to the data it stores
template <template <typename> class Container, typename Data>
concept Indexable =
  requires(Container<Data> container)
  {
    { container[0] } -> std::same_as<Data &>;
  };

#endif //SET5_INDEXABLE_H
