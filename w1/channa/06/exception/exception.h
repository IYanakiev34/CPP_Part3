#ifndef INCLUDED_EXCEPTION_
#define INCLUDED_EXCEPTION_

#include <string>
#include <sstream>
#include <exception>

class Exception: public std::exception
{
    template <typename OutType>
    friend Exception &&operator<<(Exception &&in, OutType const &out);

    std::string d_what;

    public:
        Exception() = default;

        char const *what() const noexcept(true) override;
};

template <typename OutType>
inline Exception &&operator<<(Exception &&in, OutType const &out)
{
  std::stringstream ss;
  ss << out;
  in.d_what += ss.str();

  return std::move(in);
}

#endif
