#ifndef SET4_TUPLEMOD_H
#define SET4_TUPLEMOD_H

#include <tuple>
#include <cstddef>
#include <utility>

                            // Operator to create new tuple, with the elements
                            // of tuple rhs appended to the elements of tuple
                            // lhs.
template <typename ...Lhs, typename ...Rhs>
auto operator+(std::tuple<Lhs ...> lhs, std::tuple<Rhs ...> rhs);

                              // TupleMod is a class that allows tuples to be
                              // "modified" to contain extra items.

                              // Tuple is the base tuple, and via add, you can
                              // add other items to it.
template <typename Tuple>
class TupleMod
{
  Tuple const &d_tuple;

  public:
    TupleMod(Tuple const &tuple);

                            // Add takes in a series of arguments and returns a
                            // tuple that is d_tuple with the supplied arguments
                            // appended to it.
    template <typename ...AddParams>
    auto add(AddParams &&...addParams);
  private:
                            // Workhorse function which merges two tuples.
    template <typename ...AddParams, size_t ...thisIdxs, size_t ...addedIdxs>
    auto mergeTuple(
      std::index_sequence<thisIdxs...>,
      std::tuple<AddParams...> tToAdd, std::index_sequence<addedIdxs...>
    );
};

template <typename Tuple>
TupleMod<Tuple>::TupleMod(Tuple const &tuple)
  : d_tuple(tuple)
{}

#include "add.f"
#include "operatorAdd.f"

#endif //SET4_TUPLEMOD_H
