// ml:opt = 0
// ml:ccf += -g
#include <iostream>
#include "336.hh"

template <class Vec>
void print(Vec const& v)
{
    for (auto const& i : v)
        std::cout << "(" << i[0] << "," << i[1] << ") ";
    std::cout << "\n";
}

int main()
{

    {
        std::vector<std::string> words{
            "abcd", "dcba", "lls", "s", "sssll"
        };
        print(Solution{}.palindromePairs(words));
    }

    {
        std::vector<std::string> words{
            "a","b","c","ab","ac","aa"
        };
        print(Solution{}.palindromePairs(words));
    }


    {
        std::vector<std::string> words{
            "bat","tab","cat"
        };
        print(Solution{}.palindromePairs(words));
    }

    {
        std::vector<std::string> words{
            "a", ""
        };
        print(Solution{}.palindromePairs(words));
    }



}

