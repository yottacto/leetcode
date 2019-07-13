// ml:opt = 0
// ml:ccf += -g
#include <iostream>
#include "212.hh"

template <class Vec>
void print(Vec const& v)
{
    for (auto const& s : v)
        std::cout << s << " ";
    std::cout << "\n";
}

int main()
{

    {
        std::vector<std::vector<char>> board{
            {'o', 'a', 'a', 'n'},
            {'e', 't', 'a', 'e'},
            {'i', 'h', 'k', 'r'},
            {'i', 'f', 'l', 'v'},
        };
        std::vector<std::string> words{
            "oath", "pea", "eat", "rain",
        };
        print(Solution{}.findWords(board, words));
    }

}

