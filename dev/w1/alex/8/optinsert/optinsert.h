#ifndef INCLUDED_OPTINSERT_
#define INCLUDED_OPTINSERT_

#include <ostream>

class OptInsert
{
    friend void setVerbose(std::ostream &out);

    // friend operator<<
    template<class InsertT>
    friend OptInsert &operator<<(OptInsert &optInsert, InsertT insertable);

    bool d_insert;
    std::ostream d_out;

public:
    OptInsert();

private:
    void rdbuf(std::streambuf *buffer);
};

template<class InsertT>
OptInsert &operator<<(OptInsert &optInsert, InsertT insertable)
{
    if (optInsert.d_insert)
        optInsert.d_out << insertable;
    return optInsert;
}

void setVerbose(std::ostream &out);
OptInsert &verbose();

inline OptInsert::OptInsert()
    : d_insert(false)
    , d_out(nullptr)
{
}

inline void OptInsert::rdbuf(std::streambuf *buffer)
{
    d_out.rdbuf(buffer);
    d_insert = buffer != nullptr;
}

#endif