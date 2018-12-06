#include <iostream>
#include "768.hh"

int main()
{
    std::cout << Solution{}.maxChunksToSorted({5, 4, 3, 2, 1}) << "\n";
    std::cout << Solution{}.maxChunksToSorted({2, 1, 3, 4, 4}) << "\n";
    std::cout << Solution{}.maxChunksToSorted({1, 2, 3, 4, 5}) << "\n";
    std::cout << Solution{}.maxChunksToSorted({4, 4, 2, 4, 4}) << "\n";
}

