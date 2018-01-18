#include <iostream>
#include <vector>
#include <iterator>
#include "412.hh"

template <
    template <typename, typename ...> class Vec,
    class T,
    class ...OtherArgs
>
void print(Vec<T, OtherArgs...> const& v)
{
    using std::begin;
    using std::end;
    std::copy(begin(v), end(v), std::ostream_iterator<T>(std::cout, " "));
    std::cout << "\n";
}

int main()
{
    print(Solution{}.fizzBuzz(20));
}

