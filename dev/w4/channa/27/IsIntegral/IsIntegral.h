#ifndef SET4_ISINTEGRAL_H
#define SET4_ISINTEGRAL_H

template <typename Type>
struct IsIntegral
{
  static constexpr int *p = nullptr;
  enum
  {
    integral = 1 + static_cast<Type>(0.5) == 1
  };
};

#endif //SET4_ISINTEGRAL_H
