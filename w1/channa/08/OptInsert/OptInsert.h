#ifndef SET1_OPTINSERT_H
#define SET1_OPTINSERT_H

#include <ostream>

class OptInsert
{
    friend void setVerbose(std::ostream &out);

    template <typename OutputType>
    friend OptInsert &operator<<(OptInsert &out, OutputType const &toOut);

    bool d_insert;
    std::ostream d_out;

  public:
    OptInsert();

  private:
    void rdbuf(std::streambuf *buffer);
};

void setVerbose(std::ostream &out);
OptInsert &verbose();

#include "insert.f"

#endif //SET1_OPTINSERT_H
