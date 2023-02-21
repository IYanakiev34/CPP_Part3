#include <iostream>
#include <set>

template<typename SeT>
std::ostream &operator<<(std::ostream &os, std::set<SeT> const &set)
{
    os << '{';
    bool first = true;
    for (SeT item: set)
    {
        if (first)
            first = !first;
        else
            os << ", ";
        os << item;
    }
    os << '}';
    return os;
}

using namespace std;

int main()
{
    set<size_t> const universe = {1, 2, 3, 4};
    set<set<size_t>> const subsets = {{1, 2}, {3, 4}};
    set<set<set<size_t>>> subsubsets = {{{1}, {2}}, {{3}, {4}}};

    cout << "Universe: " << universe << '\n'
         << "subsets: " << subsets << '\n'
         << "subsets: "<< subsubsets << '\n';
    // desired output: Universe: {1, 2, 3, 4}
    //                 subsets: {{1, 2}, {3, 4}}
}