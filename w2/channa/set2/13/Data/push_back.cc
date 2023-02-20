#include "Data.ih"

void Data::push_back(string const &str)
{
  d_data.push_back(std::make_shared<string>(str));
}