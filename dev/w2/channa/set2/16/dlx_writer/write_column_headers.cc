#include "dlx_writer.ih"

// Output headers, keeping track of column.
ostream &DLX_Writer::write_column_headers(ostream &out)
{
    size_t char_count = 0;
    // Output column headers.
    for (DLX::ColumnHeaderNode const *cth = d_dlx.d_root;
         d_dlx.d_root != (cth = cth->right());)
    {
        // Collect column offsets for use during row output.
        d_column_offsets[cth] = char_count;
        stringstream output;
        output << ' ' << cth->name_number()
               << '(' << cth->count() << ')';
        out << output.str();
        if (!out)
            return out;
        char_count += output.str().length();
    }

    return out;
}
