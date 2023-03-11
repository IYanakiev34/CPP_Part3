                            // Convenience function to get a copy of a
                            // value from an lvalue reference
template <typename Type>
Type getValue(Type const &arg)
{
  return arg;
}

                              // Workhorse function for tuple addition,
                              // utilizing TupleMod
template <typename ...Lhs, typename ...Rhs, size_t ...idxs>
auto addToTuple(
  std::tuple<Lhs ...> lhs, std::tuple<Rhs ...> rhs,
  std::index_sequence<idxs...>
)
{
                              // Create the "base" tuple to modify
  TupleMod<std::tuple<Lhs...>> tModL{lhs};

                              // Unpack the elements in rhs and get copies of
                              // these elements, to pass to add.
  return tModL.add(getValue(std::get<idxs>(rhs)) ...);
}


template <typename ...Lhs, typename ...Rhs>
auto operator+(std::tuple<Lhs ...> lhs, std::tuple<Rhs ...> rhs)
{
                          // We call the auxillary function addToTuple with
                          // so it has the indexes for rhs as a param. pack
  return addToTuple(lhs, rhs, std::index_sequence_for<Rhs ...>{});
}