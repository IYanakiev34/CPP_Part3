#ifndef OPTINSERT_INCLUDED_H
#define OPTINSERT_INCLUDED_H

#include <ostream>
#include <streambuf>

class OptInsert
{
    bool d_insert;
    std::ostream d_out;

public:
    OptInsert();
private:
    void rdbuf(std::streambuf *buffer);
    friend void setVerbose(std::ostream &out);

    template <typename Ins>
    friend OptInsert &operator<<(OptInsert &obj,Ins const &ins);
};

template <typename Ins>
OptInsert &operator<<(OptInsert &obj, Ins const &ins)
{
    if (obj.d_insert)
        obj.d_out << ins;
    return obj;
}

void setVerbose(std::ostream &out);
OptInsert &verbose();
#endif

