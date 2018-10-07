#include "855.hh"
#include <iostream>

int main()
{
    {
        auto r = ExamRoom(10);
        std::cerr << r.seat() << "\n";
        std::cerr << r.seat() << "\n";
        std::cerr << r.seat() << "\n";
        std::cerr << r.seat() << "\n";
        r.leave(4);
        std::cerr << r.seat() << "\n";
    }
}

