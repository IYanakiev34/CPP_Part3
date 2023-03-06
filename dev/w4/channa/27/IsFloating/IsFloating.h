#ifndef SET4_ISFLOATING_H
#define SET4_ISFLOATING_H

template <typename Type>
struct IsFloating
{
  enum
  {
    floating = 1 + static_cast<Type>(0.5) != 1
  };
};

#endif //SET4_ISFLOATING_H
