#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include <sstream>

class Data
{
    std::vector<std::string> d_data;

    // Makes Target a reference if it is a string, else does nothing
    template <typename Target>
    struct RefWrap;

public:
    explicit Data(std::vector<std::string> &&ref); // for display

    // Returns a const reference to a string and Target otherwise
    template <typename Target>
    typename RefWrap<Target>::type get(size_t idx);
};

Data::Data(std::vector<std::string> &&ref)
        : d_data{ref}
{}

template <typename Target>
struct Data::RefWrap { using type = Target; };

template <>
struct Data::RefWrap<std::string> { using type = std::string const &; };

template <typename Target>
typename Data::RefWrap<Target>::type Data::get(size_t idx)
{
    Target returnValue;
    std::stringstream ss;
    ss << d_data[idx];
    ss >> returnValue;
    if (ss.fail())
        return Target{};
    return returnValue;
}

// This is the same as the above, but with a specialization
template <>
typename Data::RefWrap<std::string>::type Data::get<std::string>(size_t idx)
{
    return d_data[idx];
}

#endif