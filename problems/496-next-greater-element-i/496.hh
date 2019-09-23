#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <stack>

auto constexpr inf = std::numeric_limits<int>::max();

struct Solution
{
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int n = nums2.size();
        std::stack<int> st;
        std::vector<int> first_greater(n);
        st.emplace(inf);
        std::unordered_map<int, int> pos;
        for (auto i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums2[i] >= st.top())
                st.pop();
            first_greater[i] = st.top();
            st.emplace(nums2[i]);
            pos[nums2[i]] = i;
        }
        std::vector<int> res;
        res.reserve(nums1.size());
        for (auto i : nums1)
            if (first_greater[pos[i]] == inf)
                res.emplace_back(-1);
            else
                res.emplace_back(first_greater[pos[i]]);
        return res;
    }
};

