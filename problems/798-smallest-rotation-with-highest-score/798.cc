#include <iostream>
#include <vector>
#include "798.hh"

int main()
{

    {
        std::vector<int> v{5, 5, 5, 5, 5};
        std::cout << Solution{}.bestRotation(v) << "\n";
    }

    {
        std::vector<int> v{2, 3, 1, 4, 0};
        std::cout << Solution{}.bestRotation(v) << "\n";
    }

    {
        std::vector<int> v{1, 3, 0, 2, 4};
        std::cout << Solution{}.bestRotation(v) << "\n";
    }

}

