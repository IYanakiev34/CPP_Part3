#include "storage.h"
#include <initializer_list>

Storage::Storage(std::initializer_list<std::size_t> const &list)
    : d_data(list)
{}
