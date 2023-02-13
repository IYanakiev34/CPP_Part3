#include "main.ih"

int main()
{
  Storage storage;

  cout << storage[Icmp::ID]           << '\n' <<
       storage[TcpUdp::PROTOCOL]   << '\n' <<
       storage[12]                 << '\n' <<
       storage['a']                << '\n' <<
       storage[12.5]               << '\n';
}