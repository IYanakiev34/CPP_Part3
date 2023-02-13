#ifndef SET1_AS_H
#define SET1_AS_H

template <typename ToType, typename FromType>
ToType as(FromType const &toConvert)
{
  return static_cast<ToType>(toConvert);
}

#endif //SET1_AS_H
