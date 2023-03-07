#ifndef ITERATOR_H
#define ITERATOR_H

#include <iterator>

template <typename IData, template<typename, typename> class Container>
struct Iterator;

template<typename IData, template <typename, typename> class Container>
bool operator==(Iterator<IData, Container> const &lhs,
        Iterator<IData, Container> const &rhs);

template<typename IData, template <typename, typename> class Container>
auto operator<=>(Iterator<IData, Container> const &lhs,
        Iterator<IData, Container> const &rhs);

template<typename IData, template <typename, typename> class Container>
std::ptrdiff_t operator-(Iterator<IData, Container> const &lhs,
        Iterator<IData, Container> const &rhs);

template<typename IData, template<typename, typename> class Container>
struct Iterator
{
    using difference_type = std::ptrdiff_t;
    using value_type = IData;
    using pointer = IData *;
    using reference = IData &;
    using iterator_category = std::random_access_iterator_tag;

    Iterator() = default;

    Iterator(typename Container<IData *,
            std::allocator<IData *>>::iterator const &current);

    friend bool operator==<IData, Container>(Iterator<IData, Container> const &lhs,
                           Iterator<IData, Container> const &rhs);

    friend auto operator<=><IData, Container>(Iterator<IData, Container> const &lhs,
                            Iterator<IData, Container> const &rhs);

    friend difference_type operator-<IData, Container>(
            Iterator<IData, Container> const &lhs, Iterator<IData, Container> const &rhs);

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

private:
    typename Container<IData *, std::allocator<IData *>>::iterator d_current;
};

#define ItTemplate template <typename IData, \
    template<typename, typename> class Container>
#define ItType Iterator<IData, Container>

ItTemplate
inline typename ItType::reference ItType::operator*() const
{
    return **d_current;
}

ItTemplate
inline typename ItType::pointer ItType::operator->() const
{
    return *d_current;
}

ItTemplate
ItType &ItType::operator-=(Iterator::difference_type diff)
{
    d_current -= diff;
    return *this;
}

ItTemplate
ItType &Iterator<IData, Container>::operator+=(Iterator::difference_type diff)
{
    d_current += diff;
    return *this;
}

ItTemplate
inline ItType ItType::operator-(Iterator::difference_type diff) const
{
    return Iterator(d_current - diff);
}

ItTemplate
inline ItType ItType::operator+(Iterator::difference_type diff) const
{
    return Iterator(d_current + diff);
}

ItTemplate
ItType ItType::operator--(int)
{
    Iterator temp(*this);
    --d_current;
    return temp;
}

ItTemplate
ItType &ItType::operator--()
{
    --d_current;
    return *this;
}

ItTemplate
ItType ItType::operator++(int)
{
    Iterator temp(*this);
    ++d_current;
    return temp;
}

ItTemplate
ItType &ItType::operator++()
{
    ++d_current;
    return *this;
}

ItTemplate
inline std::ptrdiff_t operator-(ItType const &lhs, ItType const &rhs)
{
    return lhs.d_current - rhs.d_current;
}

ItTemplate
auto operator<=>(ItType const &lhs, ItType const &rhs)
{
    return lhs.d_current <=> rhs.d_current;
}

ItTemplate
bool operator==(ItType const &lhs, ItType const &rhs)
{
    return lhs.d_current == rhs.d_current;
}

ItTemplate
ItType::Iterator(typename Container<IData *,
        std::allocator<IData *>>::iterator const &current)
        : d_current(current)
{}

#undef ItTemplate
#undef ItType
#endif