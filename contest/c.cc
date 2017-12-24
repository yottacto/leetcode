#include "c.hh"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> dead;
    std::string target;

    dead = {"0201","0101","0102","1212","2002"};
    target = "0202";
    std::cout << Solution{}.openLock(dead, target) << "\n";

    dead = {"8888"};
    target = "0009";
    std::cout << Solution{}.openLock(dead, target) << "\n";

    dead = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    target = "8888";
    std::cout << Solution{}.openLock(dead, target) << "\n";

    dead = {"0000"};
    target = "8888";
    std::cout << Solution{}.openLock(dead, target) << "\n";

}

