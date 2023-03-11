#ifndef SET4_ITERATOR_H
#define SET4_ITERATOR_H

#define ItTemplate template <typename IData, \
    template<typename> class Container>
#define FreeFuncTemplate template <typename IData, \
    template<typename> class Container>
#define ItType Iterator<IData, Container>

#include <iterator>

                                        // Forward declare template for free
                                        // operators to reference

ItTemplate
struct Iterator;

                                        // Forward declare the free operators to
                                        // bind in Iterator template
FreeFuncTemplate
bool operator==(Iterator<IData, Container> const &lhs,
        Iterator<IData, Container> const &rhs);

FreeFuncTemplate
auto operator<=>(Iterator<IData, Container> const &lhs,
        Iterator<IData, Container> const &rhs);

FreeFuncTemplate
std::ptrdiff_t operator-(Iterator<IData, Container> const &lhs,
        Iterator<IData, Container> const &rhs);

ItTemplate
struct Iterator
{
  private:
    typename Container<IData *>::iterator d_current;
  public:
                                          // Using declarations needed for
                                          // random access iterators
    using difference_type = std::ptrdiff_t;
    using value_type = IData;
    using pointer = IData *;
    using reference = IData &;
    using iterator_category = std::random_access_iterator_tag;

    Iterator() = default;
    Iterator(typename Container<IData *>::iterator const &current);


                                          // Specialize the operators with
                                          // this template's type args to
                                          // bind them.
    friend bool operator==<IData, Container>(
      Iterator<IData, Container> const &lhs,
      Iterator<IData, Container> const &rhs
    );

    friend auto operator<=><IData, Container>(
      Iterator<IData, Container> const &lhs,
      Iterator<IData, Container> const &rhs
    );

    friend difference_type operator-<IData, Container>(
      Iterator<IData, Container> const &lhs,
      Iterator<IData, Container> const &rhs
    );

                                    // Standard operations needed for Rand.
                                    // access iterators
    Iterator &operator++();
    Iterator operator++(int);
    Iterator &operator--();
    Iterator operator--(int);

    Iterator operator+(difference_type diff) const;
    Iterator operator-(difference_type diff) const;

    Iterator &operator+=(difference_type diff);
    Iterator &operator-=(difference_type diff);

    reference operator*() const;
    pointer operator->() const;
};

#include "iteratorImpl.f"

#undef ItTemplate
#undef ItType
#endif