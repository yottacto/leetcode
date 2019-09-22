#include <iostream>
#include "32.hh"

int main()
{
    std::cout << Solution{}.longestValidParentheses("(()") << "\n";
    std::cout << Solution{}.longestValidParentheses(")()())") << "\n";
}

