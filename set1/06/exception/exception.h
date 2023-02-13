#ifndef INCLUDED_EXCEPTION_
#define INCLUDED_EXCEPTION_

#include <string>
#include <sstream>
#include <exception>

                        // Exception class whose what() message can be
                        // modified via <<.
class Exception: public std::exception
{
    template <typename OutType>
    friend Exception &&operator<<(Exception &&in, OutType const &out);

                            // Store what() output in d_what
    std::string d_what;

    public:
        Exception() = default;

        char const *what() const noexcept(true) override;
};

template <typename OutType>
inline Exception &&operator<<(Exception &&in, OutType const &out)
{
                      // Use string stream to take care out conversions from
                      // int to string, etc.
  std::stringstream const ss;
  ss << out;
                      // Extend current d_what
  in.d_what += ss.str();

  return std::move(in);
}

#endif
