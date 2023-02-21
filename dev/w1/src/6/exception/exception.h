#ifndef INCLUDED_EXCEPTION_
#define INCLUDED_EXCEPTION_

#include <string>
#include <sstream>
#include <exception>

class Exception: public std::exception
{
    std::string d_what;

    template <typename Ins>
    friend Exception &&operator<<(Exception&& ex, Ins const &in)
    {
        std::stringstream ss;
        ss << in;
        ex.d_what += ss.str();
        return std::move(ex);
    }
public:
    Exception() = default;
    char const *what() const noexcept(true) override;   
};

#endif




