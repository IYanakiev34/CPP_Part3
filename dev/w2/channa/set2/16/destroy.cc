#include "dancing_links.ih"

// Never destruct during search! Nodes would be covered, therefore not found
// and not deleted, causing a memory leak.
void DLX::destroy()
{
    if (d_root == nullptr)
        return;
    
    ColumnHeaderNode *chn = d_root->right();
    while (chn != d_root) // Iterate over all column headers.
    {
        Node *item = chn->down();
        while (item != chn) // Iterate over all nodes in column.
        {
            Node *almost_dead = item;
            item = item->down();
            delete almost_dead;
        }
        ColumnHeaderNode *current = chn;
        chn = chn->right();
        delete current;
    }
    delete d_root;
}
