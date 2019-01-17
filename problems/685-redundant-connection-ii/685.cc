// ml:ccf += -g
// ml:opt = 0
#include <iostream>
#include "685.hh"

int main()
{
    {
        auto v = Solution{}.findRedundantDirectedConnection(
            {{1, 2}, {1, 3}, {2, 3}}
            );
        std::cerr << v[0] << " " << v[1] << "\n";
    }

    {
        auto v = Solution{}.findRedundantDirectedConnection(
            {{2,1},{3,1},{4,2},{1,4}}
            );
        std::cerr << v[0] << " " << v[1] << "\n";
    }

}

