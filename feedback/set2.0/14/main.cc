//JB: 0

#include "Storage/Iterator.h"

int main()
{
    Storage<int> storage;
    for (auto it = storage.rbegin(); it != storage.rend(); ++it)
        ;
}

/* JB:
   I took the liberty of writing this little main function for you.
   With it, your header file doesn't compile at all.
 */
