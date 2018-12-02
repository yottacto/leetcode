#include <iostream>
#include "488.hh"

int main()
{
    std::cout << Solution{}.findMinStep("G", "GGGGG") << "\n";

    std::cout << Solution{}.findMinStep("WRRBBW", "RB") << "\n";
    std::cout << Solution{}.findMinStep("WWRRBBWW", "WRBRW") << "\n";
    std::cout << Solution{}.findMinStep("RBYYBBRRB", "YRBGB") << "\n";
    std::cout << Solution{}.findMinStep("RRBYYBBRRBBYYBBRRB", "YRBGB") << "\n";
}

