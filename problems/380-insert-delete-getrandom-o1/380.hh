#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <unordered_map>

struct RandomizedSet
{
    std::vector<int> v;
    std::unordered_map<int, int> h;
    std::mt19937 gen;

    // Initialize your data structure here.
    RandomizedSet() : gen(std::random_device{}())
    {
    }

    // Inserts a value to the set. Returns true if the set did not already
    // contain the specified element.
    bool insert(int val)
    {
        if (h.count(val)) {
            return false;
        } else {
            v.emplace_back(val);
            h[val] = v.size() - 1;
            return true;
        }
    }

    // Removes a value from the set. Returns true if the set contained the
    // specified element.
    bool remove(int val)
    {
        if (h.count(val)) {
            auto pos = h[val];
            h[v.back()] = pos;
            std::swap(v[pos], v.back());
            v.pop_back();
            h.erase(val);
            return true;
        } else {
            return false;
        }
    }

    // Get a random element from the set.
    int getRandom()
    {
        std::array<int, 1> res;
        std::sample(v.begin(), v.end(), res.begin(), 1, gen);
        return res.front();
    }
};

