#ifndef ITERATOR_INCLUDED_SET4_H
#define ITERATOR_INCLUDED_SET4_H

#include <vector>
#include <iterator>

template <typename Data, template <typename> class Container>
struct Iterator
{

    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Data;
    using pointer = value_type *;
    using reference = value_type &;

private:
    typename Container<Data *>::iterator d_curr;

public:
    Iterator(typename Container<Data *>::iterator const &curr);

    // Should those be function template???
    friend auto operator<=>(Iterator const &lhs, Iterator const &rhs) const;
    friend bool operator==(Iterator const &lhs, Iterator const &rhs) const;
    friend int operator-(Iterator const &lhs, Iterator const &rhs) const;
    friend int operator+(Iteratro const &lhs, Iterator const &rhs) const;

    Iterator operator+(int s) const;
    Iterator operator-(int s) const;
    Iterator &operator+=(int s);
    Iterator &operator-=(int s);

    Iterator &operator++();
    Iterator operator++(int);
    Iterator &operator--();
    Iterator operator--(int);

    Data &operator*();
    Data *operator->();
};

template <typename Data, template <typename> class Container>
Iterator<Data, Container>::Iterator(typename Container<Data *>::iterator const &curr)
    : d_curr(curr)
{
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> Iterator<Data, Container>::operator+(int s) const
{
    Iterator returnVal(*this);
    returnVal.d_curr += s;
    return r;
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> Iterator<Data, Container>::operator-(int s) const
{
    Iterator returnVal(*this);
    returnVal.d_curr -= s;
    return r;
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> &Iterator<Data, Container>::operator+=(int s)
{
    d_curr += s;
    return *this;
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> &Iterator<Data, Container>::operator-=(int s)
{
    d_curr -= s;
    return *this;
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> Iterator<Data, Container>::operator--(int s)
{
    return iterator(d_curr--);
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> Iterator<Data, Container>::operator++(int s)
{
    return iterator(d_curr++);
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> &Iterator<Data, Container>::operator--()
{
    --d_curr;
    return *this;
}

template <typename Data, template <typename> class Container>
Iterator<Data, Container> &Iterator<Data, Container>::operator++()
{
    ++d_curr;
    return *this;
}

template <typename Data, template <typename> class Container>
Data &Iterator<Data, Container>::operator*()
{
    return **d_curr;
}

template <typename Data, template <typename> class Container>
Data *Iterator<Data, Container>::operator->()
{
    return *d_curr;
}
#endif