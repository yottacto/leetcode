#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>

struct RandomizedCollection
{
    std::vector<int> data;
    std::unordered_map<int, std::unordered_set<int>> pos;
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::uniform_real_distribution<> dis{0., 1.};

    // Inserts a value to the collection. Returns true if the collection did
    // not already contain the specified element.
    bool insert(int val)
    {
        auto not_contained = !pos.count(val) || pos.at(val).empty();
        pos[val].emplace(data.size());
        data.emplace_back(val);
        return not_contained;
    }

    // Removes a value from the collection. Returns true if the collection
    // contained the specified element.
    bool remove(int val)
    {
        if (!pos.count(val) || pos.at(val).empty())
            return false;
        auto p = *pos[val].begin();
        if (data.back() == val)
            p = data.size() - 1;
        pos[data.back()].erase(data.size() - 1);
        pos[data.back()].emplace(p);
        std::swap(data.back(), data[p]);
        pos[val].erase(p);
        data.pop_back();
        return true;
    }

    // Get a random element from the collection.
    int getRandom()
    {
        return data[static_cast<int>(dis(gen) * data.size())];
    }
};

