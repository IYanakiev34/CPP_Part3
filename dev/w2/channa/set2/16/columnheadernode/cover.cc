#include "../dancing_links.ih"

void DLX::ColumnHeaderNode::cover()
{
    // Remove ourselves from list of columns.
    DLX::Node::cover_lr();

    // Iterate over all lines in which we have a 1, and cover their rows (except
    // the element under this header). This means the set the row represents has
    // become unreachable by later search()es.
    for (Node *vert = down(); vert != this; vert = vert->down())
        vert->cover_rest_of_row();
}

// In one file: cover() and uncover() are always used together.

void DLX::ColumnHeaderNode::uncover()
{
    // Uncovering must proceed in reversed cover order.
    // So we move up and left instead of down and right.
    for (Node *vert = up(); vert != this; vert = vert->up())
        vert->uncover_rest_of_row();
    
    DLX::Node::uncover_lr();
}
