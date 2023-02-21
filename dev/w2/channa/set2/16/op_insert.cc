#include "dancing_links.ih"

std::ostream &operator<<(std::ostream &out, DLX const &dlx)
{
    DLX_Writer writer(dlx);
    return out << writer;
}
