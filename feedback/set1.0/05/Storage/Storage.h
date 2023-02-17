//JB: 1
#ifndef SET1_STORAGE_H
#define SET1_STORAGE_H

#include <vector>

                      // Storage of size_t elements
class Storage
{
  std::vector<size_t> d_data;

  public:
                          // Construct empty list or from init. list
    Storage() = default;
    Storage(std::initializer_list<size_t> const &list);

                          // Indexing operators
    template <typename Type>
    size_t operator[](Type const &idx) const;

    template <typename Type>
    size_t &operator[](Type const &idx);
};

                    // Template function implementations for indexing.
                    // We static cast Type to size_t whose implementations
                    // involve casting a Type variable to size_t
template <typename Type>
inline size_t &Storage::operator[](Type const &idx)
{
  return d_data[static_cast<size_t>(idx)];
}

template <typename Type>
inline size_t Storage::operator[](Type const &idx) const
{
  return d_data[static_cast<size_t>(idx)];
}

#endif //SET1_STORAGE_H
