#include <string>
#include <stack>
#include <cmath>

struct Solution
{
    int longestValidParentheses(std::string s)
    {
        std::stack<int> st;
        st.emplace(0);
        int n = s.size();
        auto res = 0;
        for (auto i = 1; i <= n; i++) {
            if (s[i - 1] == '(') {
                st.emplace(-i);
            } else {
                if (st.top() < 0) {
                    st.pop();
                    res = std::max(res, i - std::abs(st.top()));
                } else {
                    st.emplace(i);
                }
            }
        }
        return res;
    }
};

