#ifndef SET4_DATA_H
#define SET4_DATA_H

#include "../IsIntegral/IsIntegral.h"

#include <string>
#include <vector>
#include <stdexcept>

                              // A plain class that contains a vector of strings
                              // These strings are character representations of
                              // numbers.

                              // Data contains a member template get returns
                              // vector elements after a conversion.
class Data
{
  std::vector<std::string> d_data;

                            // Support struct to determine the return type of
                            // get
  template <typename Type>
  struct GetReturnType;

  public:
                          // get takes in an index (idx) of the vector to return
                          // after conversion to Type.
    template <typename Type>
    typename Data::GetReturnType<Type>::type get(size_t idx);
};

                          // Requests to conversions other than string return
                          // a value to the Type requested.
template <typename Type>
struct Data::GetReturnType
{
  using type = Type;
};
                          // string is used to signal that a reference to the
                          // value as the specified index is needed instead.
template <>
struct Data::GetReturnType<std::string>
{
  using type = std::string const &;
};

                        // We specialize get for strings, to return the data
                        // directly.
template<>
typename  Data::GetReturnType<std::string>::type
  Data::get<std::string>(size_t idx)
{
  return d_data[idx];
}

                      // Otherwise, we perform the conversion
template <typename Type>
typename  Data::GetReturnType<Type>::type Data::get(size_t idx)
try
{
                    // We perform the correct conversion based on checking for
                    // the types
  if (IsIntegral<Type>::integral)
                    // We always convert to unsigned long long, as it captures
                    // the largest numbers possible. If the type request is
                    // signed and d_data[idx] is signed, the conversion results
                    // in the correct signed result, due to overflow.
      return std::stoull(d_data[idx]);
  else
    return std::stold(d_data[idx]);
}
catch (std::invalid_argument &excep)
{
                  // If conversion cannot be performed, we return Type{}
  return Type{};
}

#endif //SET4_DATA_H
