#include <iostream>
#include "5091.hh"

int main()
{

    {
        std::vector<int> v{28004,62141,95852,39602,44613,41129,92831,36944,80519,54971};
        std::sort(v.begin(), v.end());
        for (auto i : v)
            std::cout << i << " ";
        std::cout << "\n";
        std::cout << Solution{}.minBuildTime(v, 62) << "\n";
    }

    {
        std::vector<int> v{1, 2};
        std::cout << Solution{}.minBuildTime(v, 5) << "\n";
    }

    {
        std::vector<int> v{1};
        std::cout << Solution{}.minBuildTime(v, 1) << "\n";
    }

    {
        std::vector<int> v{1, 2, 3};
        std::cout << Solution{}.minBuildTime(v, 1) << "\n";
    }

}

