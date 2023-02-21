#include "../dancing_links.ih"

DLX::ColumnHeaderNode::ColumnHeaderNode(size_t name_nr)
    : Node(this) // All pointers point to ourselves.
    , d_nr_ones(0) // Ok: column headers constructed before all normal nodes.
    , d_name_nr(name_nr)
{}
