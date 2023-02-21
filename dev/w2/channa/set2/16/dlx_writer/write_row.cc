#include "dlx_writer.ih"

ostream &DLX_Writer::write_row(ostream &out, DLX::Node const *first_node)
{
    // Rows are written left-to-right on a single row.
    if (first_node->control()->name_number() > first_node->left()->control()->name_number())
        return out;  // Skip because not the first element in this row.
    
    out << '\n';
    stringstream line; // For easy char counting.
    DLX::Node const *node = first_node;
    do
    {
        line << ' ';
        size_t const desired_offset = d_column_offsets[node->control()];
        if (line.str().length() < desired_offset) // Fill out to desired column.
            line << string(desired_offset - line.str().length(), ' ');

        line << node->control()->name_number(); // Output actual number.
        if (!line)
            break;
        node = node->right();
    } while (node != first_node);

    
    return out << line.str();
}
