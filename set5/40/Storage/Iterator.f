                                    // Definition of iterator nested class in
                                    // in Storage<Data>
template <typename Data>
struct Storage<Data>::iterator
{
                                    // Using decl. for random access iterator
    using iterator_category = std::random_access_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = Data;
    using pointer           = value_type const *;
    using reference         = value_type const &;

  private:
    typename std::vector<Data *>::iterator d_current;

  public:
                                  // Constructor needed for sort
    iterator(typename std::vector<Data *>::iterator const &current);

                                  // Free operators
    friend auto operator<=><>(iterator const &lhxs, iterator const &rhs);
    friend bool operator==<>(iterator const &lhs, iterator const &rhs);
    friend int operator-<>(iterator const &lhs, iterator const &rhs);
    friend auto operator+<>(iterator const &lhs, int step);

                                  // Operators for moving through
                                  // the vector via iterators
    iterator operator-(int step) const;
    iterator &operator--();
    iterator operator--(int);
    iterator &operator++();
    iterator operator++(int);

    iterator &operator+=(int step);
    iterator &operator-=(int step);

                                  // Access operators
    Data &operator*();
    Data *operator->();

};
