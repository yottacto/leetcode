#include <vector>
#include <stack>

struct Solution
{
    std::vector<int> dailyTemperatures(std::vector<int>& a)
    {
        int n = a.size();
        a.emplace_back(101);
        std::stack<int> st;
        st.emplace(n);
        std::vector<int> res(n);
        for (auto i = 0; i < n; i++) {
            for (; !st.empty() && a[i] > a[st.top()]; st.pop())
                res[st.top()] = i - st.top();
            st.emplace(i);
        }
        for (; st.size() > 1; st.pop())
            res[st.top()] = 0;
        return res;
    }
};

