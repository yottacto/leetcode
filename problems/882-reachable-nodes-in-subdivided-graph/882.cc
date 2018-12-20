#include <iostream>
#include <vector>
#include "882.hh"

int main()
{
    {
        std::vector<std::vector<int>> edges{
            {0, 1, 10}, {0, 2, 1}, {1, 2, 2}
        };
        std::cout << Solution{}.reachableNodes(edges, 6, 3) << "\n";
    }
}

