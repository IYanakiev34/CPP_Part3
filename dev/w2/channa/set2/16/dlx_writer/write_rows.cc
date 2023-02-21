#include "dlx_writer.ih"

ostream &DLX_Writer::write_rows(ostream &out)
{
    // Output rows.
    for (DLX::ColumnHeaderNode *cth = d_dlx.d_root;
         d_dlx.d_root != (cth = cth->right());)
    {
        // Iterate over all items in column.
        // But only first-in-row items will be printed.
        for (DLX::Node *first = cth; cth != (first = first->down());)
        { // Output row
            if (!write_row(out, first))
                return out;
        }
    }

    return out;
}
