#ifndef dancing_linkd_hh_defd
#define dancing_linkd_hh_defd

#include <cstddef>
#include <iosfwd>
#include <map>
#include <set> // Needs to be sorted! (For orderly insertion of row items.)
#include <vector>

// Dancing Links.
class DLX
{

    typedef std::size_t size_t;
    
public:

    typedef std::set<size_t> set_t;
    typedef std::set<set_t> sets_t;
    typedef std::set<sets_t> solutions_t; //FixMe: Needs lock.

private:

    class Node;
    class ColumnHeaderNode;
    typedef std::map <size_t, ColumnHeaderNode *> header_map_t;

    ColumnHeaderNode *d_root;
    std::vector<Node const *> d_solution_candidate;

public:

    // For exact cover problems:
    DLX(set_t const &universe, sets_t const &subsets);

    // Not copying data structures while backtracking is the point of DLX.
    DLX(DLX const &other) = delete;
    DLX(DLX &&tmp);
    ~DLX(); // Once destroyed, object cannot be restored except by move-assignment.

    // Add solutions to an existing set.
    void search(solutions_t &solutions, size_t stop_at = 0);

    // Create a new set, or even add to an rvalue reference.
    solutions_t search(solutions_t &&solutions = solutions_t{}, size_t stop_at = 0);
    
private:

    void destroy(); // Free all allocated memory.
    
    header_map_t create_headers(set_t const &universe);
    void add_row(set_t const &subset, header_map_t const &header_map);

    ColumnHeaderNode *pick_column();
    static std::vector<Node *> shuffle(ColumnHeaderNode *);
    
    void register_solution(solutions_t &solutions) const;
    void add_to_candidate(Node *row); // FixMe(?): integrate in cover_solution?
    void pop_from_candidate();

    static void cover_solution(DLX::Node *solution_first_node);
    static void uncover_solution(DLX::Node *solution_first_node);
    
    friend std::ostream &operator<<(std::ostream &out, DLX const &dlx);
    friend class DLX_Writer; // Only exists in op<<' anon. namespace.
};




#include "node/node.h"
// Switch between prev and next include
//#include "solution/node.hi"

#include "columnheadernode/columnheadernode.hi" // both

#include "node/inlines.hi" // without template
// Switch between prev and next include
//#include "solution/inlines.hi" // with template

#include "columnheadernode/inlines.hi" // both

#include "inlines.hi" // both

#endif //dancing_linkd_hh_defd
