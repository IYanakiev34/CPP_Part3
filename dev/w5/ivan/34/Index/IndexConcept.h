#ifndef INDEX_CONCEPT_INCLUDED_H
#define INDEX_CONCEPT_INCLUDED_H

#include <concepts>

template <template <typename> class Container, typename Data>
concept Index =
    requires(Container<Data> container) {
        {
            container[0]
            } -> std::same_as<Data &>;
    };

#endif