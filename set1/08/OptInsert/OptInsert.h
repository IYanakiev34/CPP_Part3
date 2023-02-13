#ifndef SET1_OPTINSERT_H
#define SET1_OPTINSERT_H

#include <ostream>

class OptInsert
{
    friend void setVerbose(std::ostream &out);

    template <typename OutputType>
    friend OptInsert &operator<<(OptInsert &out, OutputType const &toOut);

                            // d_insert says if OptInsert is in insert mode
    bool d_insert;
                            // Stream we insert to
    std::ostream d_out;

  public:
                          // OptInsert is set in non-insert mode
    OptInsert();

  private:
                          // Sets the rdbuf of d_out
    void rdbuf(std::streambuf *buffer);
};

                          // Free functions to interact with OptInsert
void setVerbose(std::ostream &out);
OptInsert &verbose();

#include "insert.f"

#endif //SET1_OPTINSERT_H
