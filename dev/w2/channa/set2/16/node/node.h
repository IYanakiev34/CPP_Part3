#ifndef SET2_NODE_H
#define SET2_NODE_H

#include "../NodeND/NodeND.h"

class DLX::Node : NodeND<2>
{
    enum Dimension
    {
      Horizontal,
      Vertical
    };

    //TODO: left-right and up-down actions are really the same thing.
    //TODO: So replace with non-repetitive template code.
    Node *d_left = 0;
    Node *d_right = 0;
    Node *d_up = 0;
    Node *d_down = 0;
    ColumnHeaderNode *d_control = 0;
public:
    Node(ColumnHeaderNode *control);
    Node(Node const &other) = delete;

    // Covering and uncovering are idempotent: doing it twice is harmless.
    Node * const left() const;
    Node * const right() const;
    Node * const up() const;
    Node * const down() const;
    ColumnHeaderNode * const control() const;

    // Insert other at right of this.
    void insert_on_right(Node * const other);
    void insert_on_left(Node * const other);
    void insert_below(Node * const other);
    void insert_above(Node * const other);
    
    void cover_ud() const;
    void uncover_ud();

    void cover_rest_of_row() const;
    void uncover_rest_of_row() const;
    
protected:
    void cover_lr() const;
    void uncover_lr();
};

#endif //SET2_NODE_H
