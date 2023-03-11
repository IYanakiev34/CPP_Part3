#ifndef SET5_DEREFERENCEABLE_H
#define SET5_DEREFERENCEABLE_H

template <typename Type>
concept Dereferenceable =
  requires(Type obj)
  {
    *obj;
  };

#endif //SET5_DEREFERENCEABLE_H
