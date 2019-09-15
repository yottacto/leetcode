#include <iostream>
#include "5190.hh"

int main()
{
    std::cout << Solution{}.reverseParentheses("(u(love)i)") << "\n";
    std::cout << Solution{}.reverseParentheses("(ed(et(oc))el)") << "\n";
    std::cout << Solution{}.reverseParentheses("a(bcdefghijkl(mno)p)q") << "\n";
}

