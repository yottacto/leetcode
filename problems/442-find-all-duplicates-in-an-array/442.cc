#include <iostream>
#include <vector>
#include <iterator>
#include "442.hh"

template <class T>
void print(std::vector<T> const& v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " "));
    std::cout << "\n";
}

int main()
{
    std::vector<int> v;

    v = {1, 2, 3, 2, 3};
    print(Solution{}.findDuplicates(v));
    v = {1, 1, 1, 1};
    print(Solution{}.findDuplicates(v));
    v = {1, 2, 2};
    print(Solution{}.findDuplicates(v));
    v = {10, 2, 5, 10, 9, 1, 1, 4, 3, 7};
    print(Solution{}.findDuplicates(v));
}

