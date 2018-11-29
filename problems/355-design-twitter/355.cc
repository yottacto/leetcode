#include <iostream>
#include "355.hh"

template <class Vec>
void print(Vec const& v)
{
    std::cout << "print: ";
    for (auto i : v)
        std::cout << i << ", ";
    std::cout << "\n";
}

int main()
{
    Twitter obj{};
    obj.postTweet(1, 1);
    print(obj.getNewsFeed(1));
    obj.follow(2, 1);
    print(obj.getNewsFeed(2));
    obj.unfollow(2, 1);
    print(obj.getNewsFeed(2));
}

