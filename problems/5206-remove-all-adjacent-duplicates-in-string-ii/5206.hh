#include <string>
#include <algorithm>
#include <stack>
#include <utility>

struct Solution
{
    std::string removeDuplicates(std::string s, int k)
    {
        std::stack<std::pair<char, int>> st;
        for (auto ch : s) {
            if (!st.empty() && st.top().first == ch) {
                st.top().second++;
            } else {
                st.emplace(ch, 1);
            }
            if (st.top().second == k)
                st.pop();
        }
        std::string res;
        while (!st.empty()) {
            res += std::string(st.top().second, st.top().first);
            st.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

