#include <iostream>
#include "211.hh"

int main()
{
    WordDictionary wd;
    wd.addWord("bad");
    std::cerr << wd.search("bad") << "\n";
}

