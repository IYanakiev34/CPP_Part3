#include "dancing_links.ih"

DLX::DLX(DLX &&tmp)
    : d_root(tmp.d_root)
    , d_solution_candidate(move(tmp.d_solution_candidate))
{
    tmp.d_root = nullptr;
}
