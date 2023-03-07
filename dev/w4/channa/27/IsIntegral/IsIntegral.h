#ifndef SET4_ISINTEGRAL_H
#define SET4_ISINTEGRAL_H

                              // Trait class that checks if the Type supplied is
                              // an integer
template <typename Type>
struct IsIntegral
{
                              // To check if an integral type is supplied, we
                              // see if the type does not support non integer
                              // numbers.

                              // 0.5 will be rounded to 0 if the type is
                              // integral, and thus, integral = 1 + 0 == 1 ->
                              // true
  enum
  {
    integral = 1 + static_cast<Type>(0.5) == 1
  };
};

#endif //SET4_ISINTEGRAL_H
