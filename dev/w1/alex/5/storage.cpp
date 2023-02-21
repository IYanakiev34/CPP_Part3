#include "storage.h"

Storage::Storage(std::initializer_list<size_t> const &list)
    : d_data(list)
{
}

Storage::Storage(const std::vector<size_t> &vec)
    : d_data(vec)
{
}