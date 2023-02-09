#ifndef TCP_UDP_H
#define TCP_UDP_H

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

#endif
