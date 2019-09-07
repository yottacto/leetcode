#include <iostream>
#include "5068.hh"

template <class Vec>
void print(Vec const& v)
{
    for (auto const& s : v)
        std::cout << s << ", ";
    std::cout << "\n";
}

int main()
{

    {
        std::vector<std::string> v{
            "writing code",
                "code rocks"
        };
        print(Solution{}.beforeAndAfterPuzzles(v));
    }

    {
        std::vector<std::string> v{
            "mission statement",
            "a quick bite to eat",
            "a chip off the old block",
            "chocolate bar",
            "mission impossible",
            "a man on a mission",
            "block party",
            "eat my words",
            "bar of soap"
        };
        print(Solution{}.beforeAndAfterPuzzles(v));
    }

    {
        std::vector<std::string> v{
            "a", "b", "a",
        };
        print(Solution{}.beforeAndAfterPuzzles(v));
    }

}

