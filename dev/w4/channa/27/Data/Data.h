#ifndef SET4_DATA_H
#define SET4_DATA_H

#include "../IsIntegral/IsIntegral.h"
#include "../IsFloating/IsFloating.h"

#include <string>
#include <vector>
#include <stdexcept>

class Data
{
  std::vector<std::string> d_data = {"97", "-10", "10.1", "-10.1", "asd"};

  template <typename Type>
  struct GetReturnType;

  public:
    template <typename Type>
    typename Data::GetReturnType<Type>::type get(size_t idx);
};

template <typename Type>
struct Data::GetReturnType
{
  using type = Type;
};

template <>
struct Data::GetReturnType<std::string>
{
  using type = std::string const &;
};

template<>
typename  Data::GetReturnType<std::string>::type
  Data::get<std::string>(size_t idx)
{
  return d_data[idx];
}

template <typename Type>
typename  Data::GetReturnType<Type>::type Data::get(size_t idx)
try
{
  if (IsIntegral<Type>::integral)
      return std::stoull(d_data[idx]);
  else if (IsFloating<Type>::floating)
    return std::stold(d_data[idx]);
  return Type{};
}
catch (std::invalid_argument &excep)
{
  return Type{};
}

#endif //SET4_DATA_H
