#include <iostream>
#include "460.hh"

int main()
{
    {
        LFUCache cache{2};
        cache.put(1, 1);
        cache.put(2, 2);
        std::cerr << cache.get(1) << "\n";
        cache.put(3, 3);
        std::cerr << cache.get(2) << "\n";
        std::cerr << cache.get(3) << "\n";
        cache.put(4, 4);
        std::cerr << cache.get(1) << "\n";
        std::cerr << cache.get(3) << "\n";
        std::cerr << cache.get(4) << "\n";
    }
    {
        LFUCache cache{0};
        cache.put(0, 0);
        cache.get(0);
    }
}

