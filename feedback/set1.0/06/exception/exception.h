//JB: ?
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
  std::stringstream const ss; //JB: Did you test this?
  //JB: Templates are compiled twice: summarily at the point of defintion,
  //JB: then more completely at the point of instantiation.
  ss << out;
                      // Extend current d_what
  in.d_what += ss.str();

  return std::move(in);
}

#endif

/* JB:
   If the return type is a value, the user can extend its lifetime by binding
   an explicit rvalue reference to it. They might try this with the returned
   rvalue reference, and end up with a dangling one.
 */
