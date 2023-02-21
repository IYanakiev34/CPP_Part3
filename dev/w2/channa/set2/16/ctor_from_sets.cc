#include "dancing_links.ih"

DLX::DLX(set_t const &universe, sets_t const &subsets)
    : d_root(new ColumnHeaderNode(0))
{
    // header_map, eases finding of headers when adding rows.
    header_map_t header_map = create_headers(universe);

    for (auto const &subset: subsets)
        add_row(subset, header_map);
}


// Only ever used in constructor above. So MF1F is ok.
DLX::header_map_t DLX::create_headers(set_t const &universe)
{
    header_map_t header_map;
    for (size_t item: universe)
    {
        ColumnHeaderNode *chn = new ColumnHeaderNode(item);
        // Attach row of column headers to right of d_root.
        d_root->insert_on_left(chn); // Torus, so left is 'end' of row.
        // Also build header map.
        header_map.insert({item, chn});
    }

    return header_map;
}


// Also only ever used in constructor above.
void DLX::add_row(set_t const &subset, DLX::header_map_t const &header_map)
{
    if (subset.empty())
        return; // Empty set is allowed, but nothing to do.

    set_t::const_iterator start = subset.begin(); // First item in set.
    // There are no row headers. We use the first item as a handle.
    Node *first = new Node(header_map.find(*start)->second);

    for (set_t::const_iterator it = start; it != subset.end(); ++it)
    {
        // Look up header in map to find right column to attach to.
        ColumnHeaderNode *header = header_map.find(*it)->second;
        if (it == start)
        {
            header->insert_above(first); // Torus, so above is 'end' of column.
        }
        else
        {
            Node *one = new Node(header);
            first->insert_on_left(one); // Torus, so left is 'end' of row.
            header->insert_above(one); // Torus, so above is 'end' of column.
        }
    }
}
