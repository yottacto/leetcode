// ml:opt = 0
// ml:ccf += -g
#include <iostream>
#include "126.hh"

template <class T>
void print(std::vector<T> const& vv)
{
    std::cout << "[";
    for (auto const& v : vv) {
        std::cout << "[";
        for (auto const& s : v)
            std::cout << s << ", ";
        std::cout << "], ";
    }
    std::cout << "]\n";
}

int main()
{
    print(Solution{}.findLadders(
        "hit",
        "cog",
        {"hot", "dot", "dog", "lot", "log", "cog"}
    ));
}

