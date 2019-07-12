#include <vector>
#include <algorithm>
#include <random>

struct Solution
{
    std::vector<int> copy;
    int n;
    std::random_device rd;
    std::mt19937 gen;

    Solution(std::vector<int>& nums)
        : copy(nums), n(nums.size()), gen(rd())
    {
    }

    // Resets the array to its original configuration and return it.
    std::vector<int> reset()
    {
        return copy;
    }

    // Returns a random shuffling of the array.
    std::vector<int> shuffle()
    {
        auto v = copy;
        for (auto i = 1; i < n; i++) {
            std::uniform_int_distribution<> dis(0, i);
            auto prev = dis(gen);
            std::swap(v[i], v[prev]);
        }
        return v;
    }
};

