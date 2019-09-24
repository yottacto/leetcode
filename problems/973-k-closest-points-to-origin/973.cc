#include <iostream>
#include "973.hh"

template <class Vec>
void print(Vec const& v)
{
    for (auto i : v)
        std::cout << i[0] << " " << i[1] << "\n";
}

int main()
{

    {
        std::vector<std::vector<int>> points{
            {1, 3}, {-2, 2},
        };
        print(Solution{}.kClosest(points, 1));
    }

    {
        std::vector<std::vector<int>> points{
            {3, 3}, {5, -1}, {-2, 4},
        };
        print(Solution{}.kClosest(points, 2));
    }

}

