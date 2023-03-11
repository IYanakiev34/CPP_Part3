template <template <typename> class Container, typename Data>
Insertable<Container, Data>::Insertable()
{}

template <template <typename> class Container, typename Data>
Insertable<Container, Data>::Insertable(
  Insertable<Container, Data> const &other
)
  : Container<Data>(other)
{}

template <template <typename> class Container, typename Data>
Insertable<Container, Data>::Insertable(Insertable<Container, Data> &&tmp)
  : Container<Data>(tmp)
{}

template <template <typename> class Container, typename Data>
Insertable<Container, Data>::Insertable(Container<Data> const &cont)
  : Container<Data>(cont)
{}

template <template <typename> class Container, typename Data>
Insertable<Container, Data>::Insertable(Container<Data> &&tmpCont)
  : Container<Data>(tmpCont)
{}

template <template <typename> class Container, typename Data>
Insertable<Container, Data>::Insertable(Data const &elem)
                                // Cannot do Container<Data>(elem) since if
                                // is_same<Data, size_type> then we construct
                                // container of elem Data{} elements.
  : Container<Data>(1, elem)
{}

template <template <typename> class Container, typename Data>
Insertable<Container, Data>::Insertable(Data &&tmpElem)
  : Container<Data>(1, tmpElem)
{}
