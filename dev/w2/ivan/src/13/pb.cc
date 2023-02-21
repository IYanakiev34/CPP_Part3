#include "Data.h"

void Data::push_back(const_reference str)
{
    d_data.push_back(std::make_shared<std::string>(str));
}