#ifndef ICMP_H
#define ICMP_H

enum class Icmp
{
    SECONDS   =   1,
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

#endif
