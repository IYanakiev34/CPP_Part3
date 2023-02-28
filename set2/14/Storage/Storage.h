//
// Created by Alex Swaters on 2/19/2023.
//

#ifndef INC_14_STORAGE_H
#define INC_14_STORAGE_H

#include <utility>
#include <vector>
#include <iterator>

template <typename Data>
class Storage
{
    std::vector<Data *> d_storage;

public:
    Storage() = default;

    class iterator;
    using reverse_iterator = std::reverse_iterator<iterator>;
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();

};

template <typename Data>
struct Storage<Data>::iterator
{
    friend class Storage<Data>;
    
    using iterator_category = std::random_access_iterator_tag;
    using value_type = Data;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type *;
    using reference = value_type &;

    // random access iterator interface
    iterator &operator++();
    iterator operator++(int);
    iterator &operator--();
    iterator operator--(int);
    bool operator==(iterator const &rhs) const;
    auto operator<=>(iterator const &rhs) const;
    int operator-(iterator const &rhs) const;
    iterator operator+(int n) const;
    iterator operator-(int n) const;
    Data &operator*() const;
    Data *operator->() const;
    iterator &operator=(iterator const &rhs);
    iterator(iterator const &other);
    
private:
    typename std::vector<Data *>::iterator d_it;
    iterator(typename std::vector<Data *>::iterator it);
};

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::begin()
{
    return Storage::iterator(d_storage.begin());
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::end()
{
    return Storage::iterator(d_storage.end());
}

template <typename Data>
typename Storage<Data>::reverse_iterator Storage<Data>::rbegin()
{
    return reverse_iterator(end());
}

template <typename Data>
typename Storage<Data>::reverse_iterator Storage<Data>::rend()
{
    return reverse_iterator(begin());
}

template <typename Data>
Storage<Data>::iterator::iterator(typename std::vector<Data *>::iterator it)
    : d_it(it)
{
}

template <typename Data>
typename Storage<Data>::iterator &Storage<Data>::iterator::operator++()
{
    ++d_it;
    return *this;
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::iterator::operator++(int)
{
    iterator tmp(*this);
    operator++();
    return tmp;
}

template <typename Data>
typename Storage<Data>::iterator &Storage<Data>::iterator::operator--()
{
    --d_it;
    return *this;
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::iterator::operator--(int)
{
    iterator tmp(*this);
    operator--();
    return tmp;
}

template <typename Data>
bool Storage<Data>::iterator::operator==(iterator const &rhs) const
{
    return d_it == rhs.d_it;
}

template <typename Data>
auto Storage<Data>::iterator::operator<=>(iterator const &rhs) const
{
    return d_it <=> rhs.d_it;
}

template <typename Data>
int Storage<Data>::iterator::operator-(iterator const &rhs) const
{
    return d_it - rhs.d_it;
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::iterator::operator+(int n) const
{
    return iterator(d_it + n);
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::iterator::operator-(int n) const
{
    return iterator(d_it - n);
}

template <typename Data>
Data &Storage<Data>::iterator::operator*() const
{
    return **d_it;
}

template <typename Data>
Data *Storage<Data>::iterator::operator->() const
{
    return *d_it;
}

template <typename Data>
typename Storage<Data>::iterator &Storage<Data>::iterator::operator=(
        iterator const &rhs)
{
    d_it = rhs.d_it;
    return *this;
}

template <typename Data>
Storage<Data>::iterator::iterator(iterator const &other)
    : d_it(other.d_it)
{}

#endif //INC_14_STORAGE_H
