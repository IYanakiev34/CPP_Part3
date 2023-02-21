#ifndef SET2_STORAGE_H
#define SET2_STORAGE_H

#include <vector>

template <typename Data>
class Storage
{
  std::vector<Data *> d_storage;


  public:
    class iterator;
    using reverse_iterator = std::reverse_iterator<iterator>;

    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
};

template <typename Data>
inline typename Storage<Data>::iterator Storage<Data>::begin()
{
  return iterator(std::vector<Data *>::begin());
}

template <typename Data>
inline typename Storage<Data>::iterator Storage<Data>::end()
{
  return iterator(std::vector<Data *>::end());
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator  Storage<Data>::rbegin()
{
  return std::reverse_iterator(end());
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator  Storage<Data>::rend()
{
  return std::reverse_iterator(begin());
}
#endif //SET2_STORAGE_H
