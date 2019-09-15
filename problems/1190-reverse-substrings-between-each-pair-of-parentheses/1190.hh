#include <string>
#include <stack>
#include <vector>

struct Solution
{
    std::string reverseParentheses(std::string s)
    {
        int n = s.size();
        std::stack<int> st;
        std::vector<int> portal(n + 1);
        for (auto i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.emplace(i + 1);
            } else if (s[i] == ')') {
                auto p = st.top();
                portal[i + 1] = p;
                portal[p] = i + 1;
                st.pop();
            }
        }

        auto p = 0;
        auto d = 1;
        std::string res;
        while (p != n + 1) {
            p += d;
            if (s[p - 1] == '(' || s[p - 1] == ')') {
                p = portal[p];
                d = -d;
            } else {
                res += s[p - 1];
            }
        }
        return res;
    }
};

