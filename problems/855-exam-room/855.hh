#pragma once
#include <set>
#include <iterator>

struct Pair
{
    int left;
    int right;
    int n;

    auto length() const
    {
        if (left == 0) return right - 1;
        if (right == n + 1) return n - left;
        return (right - left) / 2;
    }

    auto mid() const
    {
        if (left == 0) return 1;
        if (right == n + 1) return n;
        return (right + left) / 2;
    }
};

auto operator<(Pair const& lhs, Pair const& rhs)
{
    return lhs.length() > rhs.length()
        || (lhs.length() == rhs.length() && lhs.left < rhs.left);
}

struct ExamRoom
{
    ExamRoom(int n) : n(n)
    {
        seats.insert(0);
        seats.insert(n + 1);
        p.insert({0, n + 1, n});
    }

    int seat()
    {
        auto now = *p.begin();
        p.erase(p.begin());
        auto mid = now.mid();
        p.insert({now.left, mid, n});
        p.insert({mid, now.right, n});
        seats.insert(mid);
        return mid - 1;
    }

    void leave(int pos)
    {
        pos++;
        auto it = seats.find(pos);
        auto left = *std::prev(it);
        auto right = *std::next(it);
        seats.erase(it);
        p.erase(p.find({left, pos, n}));
        p.erase(p.find({pos, right, n}));
        p.insert({left, right, n});
    }

    std::set<Pair> p;
    std::set<int> seats;
    int n;
};

