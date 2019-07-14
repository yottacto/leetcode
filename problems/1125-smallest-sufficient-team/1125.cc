#include <iostream>
#include "1125.hh"

template <class V>
void print(V const& v)
{
    for (auto i : v)
        std::cout << i << " ";
    std::cout << "\n";
}

int main()
{

    {
        std::vector<std::string> skills{"java","nodejs","reactjs"};
        std::vector<std::vector<std::string>> people{
            {"java"},{"nodejs"},{"nodejs","reactjs"}
        };
        print(Solution{}.smallestSufficientTeam(skills, people));
    }

    {
        std::vector<std::string> skills{"algorithms","math","java","reactjs","csharp","aws"};
        std::vector<std::vector<std::string>> people{
            {"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}
        };
        print(Solution{}.smallestSufficientTeam(skills, people));
    }

}

