#include <iostream>
#include "1004.hh"


int main()
{
    {
        std::vector<int> v{1,1,1,0,0,0,1,1,1,1,0};
        std::cout << Solution{}.longestOnes(v, 2) << "\n";
    }

    {
        std::vector<int> v{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        std::cout << Solution{}.longestOnes(v, 3) << "\n";
    }

}

