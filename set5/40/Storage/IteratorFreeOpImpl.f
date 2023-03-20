auto operator<=>(NormalIter auto const &lhs, NormalIter auto const &rhs)
{
  return lhs.d_current <=> rhs.d_current;
}

bool operator==(NormalIter auto const &lhs, NormalIter auto const &rhs)
{
  return lhs.d_current == rhs.d_current;
}

int operator-(NormalIter auto const &lhs, NormalIter auto const &rhs)
{
  return lhs.d_current - rhs.d_current;
}

auto operator+(NormalIter auto const &lhs, int step)
{
  NormalIter auto ret{lhs };
  ret.d_current += step;
  return ret;
}
