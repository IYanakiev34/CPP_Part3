#include <set>
#include <iostream>

using namespace std;

template <typename ElemT>
std::ostream &operator<<(ostream &out,set<ElemT> const &set)
{
    out << '{';
    bool flag = true;
    for (auto &elem : set)
    {
        if (flag)
            flag = !flag;
        else
            out << ',';
        out << elem;
    }
    out << '}';
    return out;
}

int main (int argc, char **argv)
{
    set<set<set<string>>> sss{{{"ivan","emo"},{"nati"}},{{"pepi"}}};
    cout << sss << '\n';
    set<set<size_t>> gd {{1,2,3,4},{4,5,6,7,8}};
    cout << gd << '\n';
    return 0;
}
