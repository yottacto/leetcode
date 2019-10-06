#include <iostream>
#include "5214.hh"

int main()
{
    std::vector<int> a{1, 5, 7, 8, 5, 4, 2, 1};
    std::cout << Solution{}.longestSubsequence(a, -1) << "\n";
}

