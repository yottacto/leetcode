#include <algorithm>
#include <vector>

struct Solution
{
    int largestPerimeter(std::vector<int>& a)
    {
        std::sort(a.begin(), a.end());
        int n = a.size();
        for (auto i = n - 1; i >= 0; i--) {
            if (i - 2 >= 0 && a[i - 2] + a[i - 1] > a[i])
                return a[i] + a[i - 1] + a[i - 2];
        }
        return 0;
    }
};

