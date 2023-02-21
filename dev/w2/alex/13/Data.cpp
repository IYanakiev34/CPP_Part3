//
// Created by Alex Swaters on 2/19/2023.
//

#include "Data.h"
#include <iostream>

void Data::display() const
{
    for (auto const &str : d_data)
        std::cout << *str << '\n';
}