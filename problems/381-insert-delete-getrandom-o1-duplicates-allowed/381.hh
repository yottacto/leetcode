#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>

struct RandomizedCollection
{
    std::vector<int> data;
    std::unordered_map<int, std::unordered_set<int>> pos;

    // Inserts a value to the collection. Returns true if the collection did
    // not already contain the specified element.
    bool insert(int val)
    {
        auto not_contained = !pos.count(val);
        pos[val].emplace(data.size());
        data.emplace_back(val);
        return not_contained;
    }

    // Removes a value from the collection. Returns true if the collection
    // contained the specified element.
    bool remove(int val)
    {
        if (!pos.count(val))
            return false;
        auto p = *pos[val].begin();
        if (data.back() == val)
            p = data.size() - 1;
        pos[data.back()].erase(data.size() - 1);
        pos[data.back()].emplace(p);
        std::swap(data.back(), data[p]);
        if (pos[val].size() == 1)
            pos.erase(val);
        else
            pos[val].erase(p);
        data.pop_back();
        return true;
    }

    // Get a random element from the collection.
    int getRandom()
    {
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::uniform_int_distribution<> dis(0, data.size() - 1);
        return data[dis(gen)];
    }
};

