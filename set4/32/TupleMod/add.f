                                // To unpack d_tuple, we need a parameter
                                // pack of indices. However, we cannot simply
                                // pass in the params received by add, since
                                // this function cannot know where the indices
                                // end and the parameters start.

                                // To fix this, we pass a tuple containing the
                                // the params. However, we need the indices of
                                // this tuple as well then.

                                // We place the tuple parameter in between the
                                // indices parameters, to disambiguate index
                                // parameters.
template <typename Tuple>
template <typename ...AddParams, size_t ...thisIdxs, size_t ...addedIdxs>
auto TupleMod<Tuple>::mergeTuple(
  std::index_sequence<thisIdxs...>,
  std::tuple<AddParams...> tToAdd, std::index_sequence<addedIdxs...>
)
{
                                // We ensure that we get the value types and not
                                // references to types, in this manner, so when
                                // std::get is called, they automatically copy
                                // the value they reference.
  return std::tuple<
    typename std::tuple_element<thisIdxs, Tuple>::type ...,
    AddParams...
  >
  {
    std::get<thisIdxs>(d_tuple)..., std::get<addedIdxs>(tToAdd)...
  };
}

template<typename Tuple>
template<typename ...AddParams>
auto TupleMod<Tuple>::add(AddParams &&...addParams)
{
                                // Make index sequences for d_tuple and
                                // the addedParams tuple.
  return mergeTuple(
    std::make_index_sequence<std::tuple_size<Tuple>::value>{},
    std::tuple<AddParams...>(addParams...),
    std::make_index_sequence <sizeof... (AddParams)>{}
  );
}
