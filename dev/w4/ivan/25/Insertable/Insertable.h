#ifndef INSERTABLE_INCLUDED_H
#define INSERTABLE_INCLUDED_H

#include <iostream>
#include <vector>

template <template <typename, typename> class Container, typename Data>
struct Insertable : public Container<Data, std::allocator<Data>>
{
    using value_type = typename Container<Data, std::allocator<Data>>::value_type;
    using reference = value_type &;
    using const_reference = value_type const &;

    Insertable() = default;
    Insertable(Insertable const &obj) = default;
    Insertable(Insertable &&tmp) = default;

    Insertable(Container<Data, std::allocator<Data>> const &tmp)
        : Container<Data, std::allocator<Data>>(tmp)
    {
    }

    explicit Insertable(const_reference value)
    {
        this->push_back(value);
    }

    friend std::ostream &operator<<(std::ostream &out, Insertable const &obj)
    {
        for (auto iter = obj.begin(); iter != obj.end(); ++iter)
            out << *iter << '\n';
        return out;
    }
};

#endif