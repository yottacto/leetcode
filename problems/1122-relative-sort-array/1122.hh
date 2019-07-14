#include <algorithm>
#include <vector>
#include <unordered_map>

struct Solution
{
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2)
    {
        std::unordered_map<int, int> id;
        for (auto i = 0u; i < arr2.size(); i++)
            id[arr2[i]] = i;
        std::sort(arr1.begin(), arr1.end(), [&](auto a, auto b) {
            if (id.count(a) && id.count(b)) {
                return id[a] < id[b];
            } else if (id.count(a)) {
                return true;
            } else if (id.count(b)) {
                return false;
            } else {
                return a < b;
            }
        });
        return arr1;
    }
};

