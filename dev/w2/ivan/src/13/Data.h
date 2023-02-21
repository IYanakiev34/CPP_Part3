#ifndef DATA_INCLUDED_H
#define DATA_INCLUDED_H

#include <vector>
#include <memory>
#include <string>

class Data
{
    using DataVector = std::vector<std::shared_ptr<std::string>>;
    DataVector d_data;

public:
    using value_type = std::string;
    using const_reference = value_type const &;
    void push_back(const_reference str);
};

#endif