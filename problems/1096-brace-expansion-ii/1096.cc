#include <iostream>
#include "1096.hh"

int main()
{

    // {
    //     auto res = Solution{}.braceExpansionII("{a,b}{c{d,e}}");
    //     for (auto const& s : res)
    //         std::cout << s << " ";
    //     std::cout << "\n";
    // }

    {
        auto res = Solution{}.braceExpansionII("{a,b}c{d,e}f");
        for (auto const& s : res)
            std::cout << s << " ";
        std::cout << "\n";
    }

}

