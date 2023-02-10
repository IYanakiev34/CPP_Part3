#ifndef INCLUDED_EXCEPTION_
#define INCLUDED_EXCEPTION_

#include <string>
#include <sstream>
#include <exception>

class Exception: public std::exception
{
    std::string d_what;

    public:
        Exception() = default;

        [[nodiscard]] char const *what() const noexcept(true) override;

        std::string &str();
};

inline std::string &Exception::str()
{
    return d_what;
}

template <typename InsertT>
Exception &&operator<<(Exception &&in, InsertT insertable)
{
    std::stringstream ss;
    ss << insertable;
    in.str() += ss.str();
    return std::move(in);
}
        
#endif




