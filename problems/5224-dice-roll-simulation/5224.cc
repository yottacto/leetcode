#include <iostream>
#include "5224.hh"

int main()
{

    {
        std::vector<int> v{1, 1, 2, 2, 2, 3};
        std::cout << Solution{}.dieSimulator(2, v) << "\n";
    }

}

