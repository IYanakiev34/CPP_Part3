#ifndef STORAGE_H
#define STORAGE_H

#include <initializer_list>
#include <vector>

class Storage
{
    std::vector<std::size_t> d_data;
public:
    Storage() = default;
    Storage(std::initializer_list<std::size_t> const &list);

    template <typename Idx>
    std::size_t operator[](Idx idx) const
    {
        return d_data[static_cast<std::size_t>(idx)];
    }

    template <typename Idx>
    std::size_t &operator[](Idx idx)
    {
        return d_data[static_cast<std::size_t>(idx)];
    }
};


#endif
