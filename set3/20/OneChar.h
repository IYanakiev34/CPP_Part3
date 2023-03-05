#ifndef SET3_ONECHAR_H
#define SET3_ONECHAR_H

                        // Simple type promotion class from char.
template <char c>
struct OneChar
{
  enum {value = c };
};

#endif //SET3_ONECHAR_H
