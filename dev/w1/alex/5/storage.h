#ifndef INC_5_STORAGE_H
#define INC_5_STORAGE_H

#include <vector>

class Storage
{
    std::vector<size_t> d_data;

public:
    Storage() = default;

    Storage(std::initializer_list<size_t> const &list);
    Storage(std::vector<size_t> const &vec);

    template<typename IndexT>
    size_t operator[](IndexT idx) const;

    template<typename IndexT>
    size_t &operator[](IndexT idx);
};

template<typename IndexT>
inline size_t Storage::operator[](IndexT idx) const
{
    return d_data[static_cast<size_t>(idx)];
}

template<typename IndexT>
inline size_t &Storage::operator[](IndexT idx)
{
    return d_data[static_cast<size_t>(idx)];
}

#endif //INC_5_STORAGE_H
