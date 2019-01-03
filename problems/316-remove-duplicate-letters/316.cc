#include <iostream>
#include "316.hh"

int main()
{
    std::cout << Solution{}.removeDuplicateLetters("bcabc") << "\n";
    std::cout << Solution{}.removeDuplicateLetters("cbacdcbc") << "\n";
    std::cout << Solution{}.removeDuplicateLetters("acbabc") << "\n";
    std::cout << Solution{}.removeDuplicateLetters("abcacb") << "\n";
    std::cout << Solution{}.removeDuplicateLetters("acbacb") << "\n";
}

