#include "main.ih"

class Demo
{};

void fun(int first, int second)
{}
void fun(Demo &&dem1, Demo &&dem2)
{}

int main()
{
  forwarder<void(int, int)>(fun, 1, 1);
  forwarder<void(Demo &&, Demo&&)>(fun, Demo{}, Demo{});
}