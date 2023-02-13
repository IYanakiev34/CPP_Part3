#ifndef SET1_STORAGE_H
#define SET1_STORAGE_H

#include <vector>

class Storage
{
    std::vector<size_t> d_data;

  public:
    Storage() = default;
    Storage(std::initializer_list<size_t> const &list);

    template <typename Type>
    size_t operator[](Type const &idx) const;

    template <typename Type>
    size_t &operator[](Type const &idx);
};

template <typename Type>
inline size_t &Storage::operator[](Type const &idx)
{
  return d_data[static_cast<Type>(idx)];
}

template <typename Type>
inline size_t Storage::operator[](Type const &idx) const
{
  return d_data[static_cast<Type>(idx)];
}

#endif //SET1_STORAGE_H
