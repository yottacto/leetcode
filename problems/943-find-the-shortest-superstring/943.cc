#include <iostream>
#include "943.hh"


int main()
{

    {
        std::vector<std::string> v{ "alex", "loves", "leetcode"};
        std::cout << Solution{}.shortestSuperstring(v) << "\n";
    }

    {
        std::vector<std::string> v{"catg","ctaagt","gcta","ttca","atgcatc"};
        std::cout << Solution{}.shortestSuperstring(v) << "\n";
    }

}

