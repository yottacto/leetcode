#include <iostream>
#include "1146.hh"

int main()
{
    SnapshotArray sa(3);
    sa.set(0, 5);
    sa.snap();
    sa.set(0, 6);
    std::cout << sa.get(0, 0) << "\n";
}

