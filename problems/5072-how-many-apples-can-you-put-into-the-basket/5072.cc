// ml:opt = 0
// ml:ccf += -g
#include <iostream>
#include "5072.hh"

int main()
{
    {
        std::vector<int> v{100, 200, 150, 1000};
        std::cout << Solution{}.maxNumberOfApples(v) << "\n";
    }

    {
        std::vector<int> v{900,950,800,1000,700,800};
        std::cout << Solution{}.maxNumberOfApples(v) << "\n";
    }

}

