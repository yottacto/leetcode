#include <vector>
#include <stack>
#include <limits>

auto constexpr inf = std::numeric_limits<int>::max();

struct Solution
{
    std::vector<int> nextGreaterElements(std::vector<int>& nums)
    {
        std::stack<int> st;
        int n = nums.size();
        std::vector<int> res(n);
        st.emplace(inf);
        for (auto i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i % n] >= st.top())
                st.pop();
            if (i < n)
                res[i] = st.top() == inf ? -1 : st.top();
            st.emplace(nums[i % n]);
        }
        return res;
    }
};

