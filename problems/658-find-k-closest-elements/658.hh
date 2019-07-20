#include <vector>
#include <algorithm>

struct Solution
{
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x)
    {
        int n = arr.size();
        int r = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;
        for (auto i = 0; i < k; i++) {
            if (l >= 0 && r < n) {
                auto dl = x - arr[l];
                auto dr = arr[r] - x;
                if (dl <= dr)
                    l--;
                else
                    r++;
            } else if (l >= 0) {
                l--;
            } else {
                r++;
            }
        }
        return {arr.begin() + l + 1, arr.begin() + r};
    }
};

