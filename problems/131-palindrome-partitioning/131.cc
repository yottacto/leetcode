// ml:run = time -p $bin
#include <iostream>
#include "131.hh"

int main()
{
    std::string s(50, 'a');
    auto res = Solution{}.partition(s);
    // std::cout << res.size() << "\n";
    std::cout << res[0][0] << "\n";
}

