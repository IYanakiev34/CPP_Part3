#include "main.ih"

                    // From cppreference:
                    // https://en.cppreference.com/w/cpp/utility/apply
template<typename... Ts>
std::ostream& operator<<(std::ostream& os, std::tuple<Ts...> const& theTuple)
{
  std::apply
    (
      [&os](Ts const&... tupleArgs)
      {
        os << '[';
        std::size_t n{0};
        ((os << tupleArgs << (++n != sizeof...(Ts) ? ", " : "")), ...);
        os << ']';
      }, theTuple
    );
  return os;
}
template <typename Arg, typename... Args>
void doPrint(std::ostream& out, Arg&& arg, Args&&... args)
{
  out << std::forward<Arg>(arg);
  ((out << ',' << std::forward<Args>(args)), ...);
  out << '\n';
}

int main()
{
  tuple<int, double> t1{ 1, 12.5 };
  tuple<string, int> ts{"asd", 123};

  auto t2 = ts + t1;

  cout << t2 + t2;
}