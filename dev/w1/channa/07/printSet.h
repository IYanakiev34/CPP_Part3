#ifndef SET1_PRINTSET_H
#define SET1_PRINTSET_H

#include <ostream>
#include <set>

template <typename ElemT>
std::ostream &operator<<(std::ostream &out, std::set<ElemT> const &toOut)
{
  out << '{';

  bool prevItemExists = false;

  for (auto const &elem : toOut)
  {
    if (prevItemExists)
      out << ", ";

                    // If out is a subset, then the template will be recursively
                    // called, otherwise the default << for this type will be
                    // used.
    out << elem;

    prevItemExists = true;
  }

  return out << '}';
}

#endif //SET1_PRINTSET_H