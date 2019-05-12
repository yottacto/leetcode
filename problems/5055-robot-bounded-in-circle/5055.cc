// ml:std = c++11
#include <iostream>
#include "5055.hh"

int main()
{
    std::cout << Solution{}.isRobotBounded("LRRRRLLLRL") << "\n";
    std::cout << Solution{}.isRobotBounded("RRGRRGLLLRLGGLGLLGRLRLGLRLRRGLGGLLRRRLRLRLLGRGLGRRRGRLG") << "\n";
    std::cout << Solution{}.isRobotBounded("GL") << "\n";
}

