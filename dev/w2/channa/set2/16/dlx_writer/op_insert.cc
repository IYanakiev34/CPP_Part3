#include "dlx_writer.ih"

std::ostream &operator<<(std::ostream &out, DLX_Writer &dlx)
{
    // If headers fail to write, skip the nodes.
    if (dlx.write_column_headers(out))
        dlx.write_rows(out);

    return out;
}
