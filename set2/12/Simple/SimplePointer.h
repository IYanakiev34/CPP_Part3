#ifndef SET2_SIMPLEPOINTER_H
#define SET2_SIMPLEPOINTER_H

template <typename Data>
class Simple<Data *>
{
  Data *d_ptr = 0;

  public:
    Simple() = default;
    explicit Simple(Data &data);
    explicit Simple(Data *other );

    Data &get();
};

template <typename Data>
inline Simple<Data *>::Simple(Data &data)
  :
  d_ptr(&data)
{}

template <typename Data>
inline Simple<Data *>::Simple(Data *const other)
  :
  d_ptr(other)
{}

template <typename Data>
inline Data &Simple<Data *>::get()
{
  return *d_ptr;
}

#endif //SET2_SIMPLEPOINTER_H
