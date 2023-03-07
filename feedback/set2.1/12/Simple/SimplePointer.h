//JB: ?
#ifndef SET2_SIMPLEPOINTER_H
#define SET2_SIMPLEPOINTER_H

//JB: I wouldn't use the '.h' extension, because the user might expect to be
//JB: able to include this file, which they cannot as it'd specialize an
//JB: unknown class.

template <typename Data>
class Simple<Data *>
{
  //JB: Specialization a bit poiintless in terms of data...
  Data *d_ptr = 0;

  public:
    Simple() = default;
    //JB: I wonder what kind of class this is that doesn't own its data.
    //JB: This makes the specialization too different from the general case:
    //JB: they behave differently.
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
