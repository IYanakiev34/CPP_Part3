#ifndef SET2_DATA_H
#define SET2_DATA_H

#include <vector>
#include <memory>

class Data
{
  using DataVector = std::vector<std::shared_ptr<std::string>>;
  DataVector d_data;

  public:
    using value_type = std::string;
    using const_reference = value_type const &;

    void push_back(std::string const &str);
};

#endif //SET2_DATA_H
