#ifndef SET4_TUPLEMOD_H
#define SET4_TUPLEMOD_H

#include <tuple>
#include <cstddef>
#include <utility>

template <typename Tuple>
class TupleMod
{
  Tuple const &d_tuple;

  public:
    TupleMod(Tuple const &tuple);

    template <typename ...AddParams>
    auto add(AddParams &&...addParams);
  private:
    template <typename ...AddParams>
    auto mergeTuple(std::tuple<AddParams...> tToAdd);

    template <typename ...AddParams, size_t ...thisIdxs, size_t ...addedIdxs>
    auto mergeTupleAux(
      std::index_sequence<thisIdxs...>,
      std::tuple<AddParams...> tToAdd, std::index_sequence<addedIdxs...>
    );
};


template <typename Tuple>
TupleMod<Tuple>::TupleMod(Tuple const &tuple)
  : d_tuple(tuple)
{}

template <typename Tuple>
template <typename ...AddParams, size_t ...thisIdxs, size_t ...addedIdxs>
auto TupleMod<Tuple>::mergeTupleAux(
  std::index_sequence<thisIdxs...>,
  std::tuple<AddParams...> tToAdd,
  std::index_sequence<addedIdxs...>
)
{
  return std::tuple<
    typename std::tuple_element<thisIdxs, Tuple>::type ...,
    AddParams...
  >{
    std::get<thisIdxs>(d_tuple)...,
    std::get<addedIdxs>(tToAdd)...
  };
}

template <typename Tuple>
template <typename ...AddParams>
auto TupleMod<Tuple>::mergeTuple(std::tuple<AddParams...> tToAdd)
{
  return mergeTupleAux(
    std::make_index_sequence<std::tuple_size<Tuple>::value>{},
    tToAdd, std::make_index_sequence<sizeof... (AddParams)>{}
  );
}

template<typename Tuple>
template<typename ...AddParams>
auto TupleMod<Tuple>::add(AddParams &&...addParams)
{
  return mergeTuple(std::tuple<AddParams...>(addParams...));
}

template <typename ...Lhs, typename ...Rhs, size_t ...idxs>
auto addToTuple(
  std::tuple<Lhs ...> lhs, std::tuple<Rhs ...> rhs,
  std::index_sequence<idxs...>
)
{
  TupleMod<std::tuple<Lhs...>> tModL{lhs};
  return tModL.add(std::get<idxs>(rhs) ...);
}

template <typename ...Lhs, typename ...Rhs>
auto operator+(std::tuple<Lhs ...> lhs, std::tuple<Rhs ...> rhs)
{
  return addToTuple(lhs, rhs, std::index_sequence_for<Rhs ...>{});
}


#endif //SET4_TUPLEMOD_H
