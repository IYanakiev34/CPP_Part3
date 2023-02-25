#ifndef SET3_ONECHAR_H
#define SET3_ONECHAR_H

template <char c>
struct OneChar
{
  enum {value = c };
};

#endif //SET3_ONECHAR_H
