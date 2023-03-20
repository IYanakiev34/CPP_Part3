#include "main.ih"

template<template <typename> class Container, typename Data>
  requires Indexable<Container, Data>
void test(Container<Data> cd)
{
  cd[0];
}

int main()
{
//  test(10);
    test(std::vector<int>{});
}