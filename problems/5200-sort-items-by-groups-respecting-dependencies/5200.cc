#include <iostream>
#include "5200.hh"

template <class Vec>
void print(Vec const& v)
{
    for (auto i : v)
        std::cout << i << " ";

    std::cout << "\n";
}

int main()
{
    std::vector<int> v{2, 0, -1, 3, 0};
    std::vector<std::vector<int>> before{{2, 1, 3}, {2, 4}, {}, {}, {}};

    print(Solution{}.sortItems(5, 5, v, before));
}

