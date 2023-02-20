#ifndef STORAGE_INCLUDED_H
#define STORAGE_INCLUDED_H

#include <vector>
#include <iterator>
#include <utility>

template <typename Data>
class Storage
{
    std::vector<Data *> d_storage;

public:
    Storage() = default;
    Storage(std::vector<Data *> storage);

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

    // Types
    using iterator_category = std::random_access_iterator_tag;
    using value_type = Data;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type *;
    using reference = value_type &;

    iterator(iterator const &other);

    iterator &operator++();
    iterator operator++(int);
    iterator &operator--();
    iterator operator--(int);

    iterator &operator=(iterator const &other);
    bool operator==(iterator const &other) const;
    bool operator!=(iterator const &other) const;
    auto operator<=>(iterator const &other) const;
    int operator-(iterator const &other) const;

    iterator operator+(int pos) const;
    iterator operator-(int pos) const;

    Data &operator*() const;
    Data *operator->() const;

private:
    typename std::vector<Data *>::iterator d_iter;
    iterator(typename std::vector<Data *>::iterator it);
};

// Storage

template <typename Data>
Storage<Data>::Storage(std::vector<Data *> storage)
    : d_storage(std::move(storage))
{
}

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

// Iterator
template <typename Data>
Storage<Data>::iterator::iterator(iterator const &other)
    : d_iter(other.d_iter)
{
}

template <typename Data>
typename Storage<Data>::iterator &Storage<Data>::iterator::operator++()
{
    ++d_iter;
    return *this;
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::iterator::operator++(int)
{
    iterator tmp(*this);
    operator++();
    tmp;
}

template <typename Data>
typename Storage<Data>::iterator &Storage<Data>::iterator::operator--()
{
    --d_iter;
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
bool Storage<Data>::iterator::operator!=(iterator const &other) const
{
    return !(d_iter == other.d_iter);
}

template <typename Data>
typename Storage<Data>::iterator &Storage<Data>::iterator::operator=(iterator const &other)
{
    d_iter = other.d_iter;
    return *this;
}

template <typename Data>
bool Storage<Data>::iterator::operator==(iterator const &other) const
{
    return d_iter == other.d_iter;
}

template <typename Data>
auto Storage<Data>::iterator::operator<=>(iterator const &other) const
{
    return d_iter <=> other.d_iter;
}

template <typename Data>
int Storage<Data>::iterator::operator-(iterator const &other) const
{
    return d_iter - other.d_iter;
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::iterator::operator+(int pos) const
{
    return iterator(d_iter + pos);
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::iterator::operator-(int pos) const
{
    return iterator(d_iter - pos);
}

template <typename Data>
Data &Storage<Data>::iterator::operator*() const
{
    return **d_iter;
}

template <typename Data>
Data *Storage<Data>::iterator::operator->() const
{
    return *d_iter;
}

#endif