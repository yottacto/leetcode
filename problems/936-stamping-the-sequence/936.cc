#include <iostream>
#include "936.hh"

template <class Vec>
void print(Vec const& v)
{
    for (auto i : v)
        std::cout << i << ",";
    std::cout << "\n";
}

int main()
{
    print(Solution{}.movesToStamp("abc", "ababc"));
    print(Solution{}.movesToStamp("abca", "aabcaca"));
}

