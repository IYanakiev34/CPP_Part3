#ifndef ITERATOR_H
#define ITERATOR_H

#include <iterator>

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

    template<typename IData2, template<typename, typename> class Container2>
    friend bool operator==(Iterator<IData2, Container2> const &lhs,
                           Iterator<IData2, Container2> const &rhs);

    template<typename IData2, template<typename, typename> class Container2>
    friend auto operator<=>(Iterator<IData2, Container2> const &lhs,
                            Iterator<IData2, Container2> const &rhs);

    template<typename IData2, template<typename, typename> class Container2>
    friend difference_type operator-(Iterator<IData2, Container2> const &lhs,
                                     Iterator<IData2, Container2> const &rhs);

    Iterator &operator++();

    Iterator operator++(int);

    Iterator &operator--();

    Iterator operator--(int);

    Iterator operator+(difference_type n) const;

    Iterator operator-(difference_type n) const;

    Iterator &operator+=(difference_type n);

    Iterator &operator-=(difference_type n);

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
ItType &ItType::operator-=(Iterator::difference_type n)
{
    d_current -= n;
    return *this;
}

ItTemplate
ItType &Iterator<IData, Container>::operator+=(Iterator::difference_type n)
{
    d_current += n;
    return *this;
}

ItTemplate
inline ItType ItType::operator-(Iterator::difference_type n) const
{
    return Iterator(d_current - n);
}

ItTemplate
inline ItType ItType::operator+(Iterator::difference_type n) const
{
    return Iterator(d_current + n);
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
auto operator<=>(const ItType &lhs, const ItType &rhs)
{
    return lhs.d_current <=> rhs.d_current;
}

ItTemplate
bool operator==(const ItType &lhs, const ItType &rhs)
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