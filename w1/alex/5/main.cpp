#include <iostream>
#include "storage.h"
#include <numeric>

enum class TcpUdp
{
    SECONDS = 1,
    MU_SECONDS,
    PROTOCOL,       // tcp/udp
    SRC,
    DST,
    SPORT,
    DPORT,
    SENTPACKETS,
    SENTBYTES,
    RECVDPACKETS,
    RECVDBYTES,
    nFields,
};

enum class Icmp
{
    SECONDS = 1,
    MU_SECONDS,
    SRC,
    DST,
    ID,
    SENTPACKETS,
    SENTBYTES,
    RECVDPACKETS,
    RECVDBYTES,
    nFields,
};

int main()
{
    std::vector<size_t> range100;
    for (size_t idx = 0; idx != 100; ++idx)
        range100.emplace_back(idx);
    Storage storage{range100};
    std::cout << storage[Icmp::ID] << '\n' <<
              storage[TcpUdp::PROTOCOL] << '\n' <<
              storage[12] << '\n' <<
              storage['a'] << '\n' <<
              storage[12.5] << '\n';
}
