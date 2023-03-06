template <template <typename> class Container, typename Data>
std::ostream &operator<<(
  std::ostream &out, Insertable<Container, Data> insertable
)
{
  copy(
  insertable.begin(), insertable.end(),
  std::ostream_iterator<Data>(out, " ")
  );
  return out;
}
