#ifndef SET5_COMPARINGDEMO_H
#define SET5_COMPARINGDEMO_H

template <typename Lhs, typename Rhs>
  requires
    requires(Lhs lhs, Rhs rhs)
    {
      lhs == rhs;
      rhs == lhs;

      lhs != rhs;
      rhs != lhs;

      lhs < rhs;
      rhs < lhs;

      lhs > rhs;
      rhs > lhs;

      lhs <= rhs;
      rhs <= lhs;

      lhs >= rhs;
      rhs >= lhs;
    }
auto compare();

template <typename Type>
  requires
    requires(Type lhs, Type rhs)
    {
      lhs == rhs;
      rhs == lhs;

      lhs != rhs;
      rhs != lhs;

      lhs < rhs;
      rhs < lhs;

      lhs > rhs;
      rhs > lhs;

      lhs <= rhs;
      rhs <= lhs;
    }
class Compare;

#endif //SET5_COMPARINGDEMO_H
