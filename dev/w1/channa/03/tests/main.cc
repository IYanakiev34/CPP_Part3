#include "main.ih"


int main()
{
  size_t num = 10;
  size_t capacity = num;
  int *ip = rawCapacity<int>(capacity);
  for (size_t i = 0; i != num; ++i)
    ip[i] = 0;

  operator delete(ip);
}