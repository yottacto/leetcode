#include <iostream>
#include "736.hh"

int main()
{
    std::cout << Solution{}.evaluate("(add 1 2)") << "\n";
    std::cout << Solution{}.evaluate("(let 4)") << "\n";
    std::cout << Solution{}.evaluate("(mult 3 (add 2 3))") << "\n";
    std::cout << Solution{}.evaluate("(let x 2 (mult x 5))") << "\n";
    std::cout << Solution{}.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))") << "\n";
    std::cout << Solution{}.evaluate("(let x 3 x 2 x)") << "\n";
    std::cout << Solution{}.evaluate("(let x 1 y 2 x (add x y) (add x y))") << "\n";
    std::cout << Solution{}.evaluate("(let x 2 (add (let x 3 (let x 4 x)) x))") << "\n";
    std::cout << Solution{}.evaluate("(let a1 3 b2 (add a1 1) b2)") << "\n";
}

