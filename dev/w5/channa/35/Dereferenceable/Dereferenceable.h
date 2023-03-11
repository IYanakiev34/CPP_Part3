#ifndef SET5_DEREFERENCEABLE_H
#define SET5_DEREFERENCEABLE_H

                                // A concept which ensures that some type
                                // supports the dereference operator.
template <typename Type>
concept Dereferenceable =
  requires(Type obj)
  {
    *obj;
  };

#endif //SET5_DEREFERENCEABLE_H
