#include "dancing_links.hh"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main()
    try
    {
        set<size_t> const universe = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
        set<set<size_t>> const subsets =
            {  // Just some random exact cover problem that does have solutions.
                {                           },
                { 1, 2,                     },
                {                           },
                {       3, 4                },
                {             5,    7,    9 },
                {          4,       7,  8   },
                {                6          },
                { 1,             6,       9 },
                {                       8   },
                { 1,    3,    5,    7,    9 },
                { 1, 2,    4                },
                {       3,    5,    7       },
                {                6,       9 },
                {                   7, 8    },
            };

        DLX dancer(universe, subsets);

        cout << "Created a Dancing Links object:\n"
             << dancer << '\n';
    }
    catch (exception const &ex) // Display any info we can.
    {
        cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
    catch (...) // At least ensure stack unwind.
    {
        throw;
    }
