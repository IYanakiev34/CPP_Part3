//JB: ?
#ifndef SET1_AS_H
#define SET1_AS_H

                            // Converts toConvert to type toType, which is
                            // provided as an explicit type
template <typename ToType, typename FromType>
ToType as(FromType const &toConvert)
{
  return static_cast<ToType>(toConvert);
}

#endif //SET1_AS_H

/* JB:
   This works suboptimally on rvalue references.
 */
