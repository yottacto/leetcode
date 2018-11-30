#pragma once
#include <vector>

// // This is the interface that allows for creating nested lists.
// // You should not implement it, or speculate about its implementation
// struct NestedInteger
// {
//     // Return true if this NestedInteger holds a single integer, rather than a
//     // nested list.
//     bool isInteger() const;

//     // Return the single integer that this NestedInteger holds, if it holds a
//     // single integer
//     // The result is undefined if this NestedInteger holds a nested list
//     int getInteger() const;

//     // Return the nested list that this NestedInteger holds, if it holds a
//     // nested list
//     // The result is undefined if this NestedInteger holds a single integer
//     const std::vector<NestedInteger> &getList() const;
// };

struct NestedIterator
{
    std::vector<int> data;

    decltype(data)::iterator it;

    void flat(std::vector<NestedInteger> const& list)
    {
        for (auto const& v : list) {
            if (v.isInteger())
                data.emplace_back(v.getInteger());
            else
                flat(v.getList());
        }
    }

    NestedIterator(std::vector<NestedInteger> const& nestedList)
    {
        flat(nestedList);
        it = data.begin();
    }

    int next()
    {
        return *(it++);
    }

    bool hasNext()
    {
        return it != data.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

