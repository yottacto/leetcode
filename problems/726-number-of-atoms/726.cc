#include <iostream>
#include "726.hh"

int main()
{
    std::cout << Solution{}.countOfAtoms("H2O") << "\n";
    std::cout << Solution{}.countOfAtoms("K4(ON(SO3)2)2") << "\n";
    std::cout << Solution{}.countOfAtoms("Mg(OH)2") << "\n";
    std::cout << Solution{}.countOfAtoms("HHHHHHHH") << "\n";
}

