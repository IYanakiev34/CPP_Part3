#ifndef SET5_COMPARINGDEMO_H
#define SET5_COMPARINGDEMO_H

                            // template function declaration which uses Lhs /
                            // Rhs such that they should be comparable.

template <typename Lhs, typename Rhs>
  requires
    requires(Lhs lhs, Rhs rhs)
    {
                            // We have to compare lhs / rhs to ensure
                            // commutativity of application (though not of
                            // result)
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

                                  // template class delcaration with a template
                                  // type parameter which should be comparable
template <typename Type>
  requires
    requires(Type lhs, Type rhs)
    {
      lhs == rhs;
      lhs != rhs;

      lhs < rhs;
      lhs <= rhs;

      lhs > rhs;
      lhs <= rhs;
    }
class Compare;

#endif //SET5_COMPARINGDEMO_H
