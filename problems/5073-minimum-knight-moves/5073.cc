// ml:run = time -p $bin
#include <iostream>
#include "5073.hh"

int main()
{
    std::cout << Solution{}.minKnightMoves(2, 1) << "\n";
    std::cout << Solution{}.minKnightMoves(5, 5) << "\n";
    std::cout << Solution{}.minKnightMoves(11, 248) << "\n";
    std::cout << Solution{}.minKnightMoves(97, 133) << "\n";
    std::cout << Solution{}.minKnightMoves(209, -58) << "\n";

}

