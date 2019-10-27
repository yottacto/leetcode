#include <vector>

// // This is the custom function interface.
// // You should not implement it, or speculate about its implementation
// class CustomFunction {
// public:
//     // Returns f(x, y) for any given positive integers x and y.
//     // Note that f(x, y) is increasing with respect to both x and y.
//     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
//     int f(int x, int y);
// };


struct Solution
{
    std::vector<std::vector<int>> findSolution(CustomFunction& customfunction, int z)
    {
        std::vector<std::vector<int>> res;
        for (auto x = 1; x <= 1000; x++)
            for (auto y = 1; y <= 1000; y++)
                if (customfunction.f(x, y) == z)
                    res.emplace_back(std::vector<int>{x, y});
        return res;
    }
};

