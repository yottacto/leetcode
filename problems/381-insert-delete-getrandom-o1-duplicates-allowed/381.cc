#include <iostream>
#include <iomanip>
#include "381.hh"

int main()
{

    // ["RandomizedCollection", "insert", "insert", "insert", "insert", "insert", "insert", "remove", "remove", "remove", "remove", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
    // [[],                     [1],      [1],      [2],      [1],      [2],      [2],      [1],      [2],      [2],      [2],      [],          [],          [],          [],          [],          [],          [],          [],          [],          []]
    RandomizedCollection rc{};
    std::cout << std::boolalpha << rc.insert(1) << "\n";
    std::cout << std::boolalpha << rc.insert(1) << "\n";
    std::cout << std::boolalpha << rc.insert(2) << "\n";
    std::cout << std::boolalpha << rc.insert(1) << "\n";
    std::cout << std::boolalpha << rc.insert(2) << "\n";
    std::cout << std::boolalpha << rc.insert(2) << "\n";
    std::cout << std::boolalpha << rc.remove(1) << "\n";
    std::cout << std::boolalpha << rc.remove(2) << "\n";
    std::cout << std::boolalpha << rc.remove(2) << "\n";
    std::cout << std::boolalpha << rc.remove(2) << "\n";

    std::cout << rc.getRandom() << "\n";
    std::cout << rc.getRandom() << "\n";
    std::cout << rc.getRandom() << "\n";
    std::cout << rc.getRandom() << "\n";
    std::cout << rc.getRandom() << "\n";
    std::cout << rc.getRandom() << "\n";
    std::cout << rc.getRandom() << "\n";
}

