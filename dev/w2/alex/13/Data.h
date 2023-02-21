//
// Created by Alex Swaters on 2/19/2023.
//

#ifndef INC_13_DATA_H
#define INC_13_DATA_H

#include <vector>
#include <memory>

class Data
{
    using DataVector = std::vector<std::shared_ptr<std::string>>;
    DataVector d_data;

public:
    using value_type = std::string;
    void push_back(std::string const &str);
    void display() const;
};

inline void Data::push_back(std::string const &str)
{
    d_data.push_back(std::make_shared<std::string>(str));
}


#endif //INC_13_DATA_H
