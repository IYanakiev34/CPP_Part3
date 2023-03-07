#ifndef SET3_ONECHAR_H
#define SET3_ONECHAR_H

                        // Simple type promotion class from char.
template <char ch>
struct OneChar
{
  enum {value = ch };
};

#endif //SET3_ONECHAR_H
