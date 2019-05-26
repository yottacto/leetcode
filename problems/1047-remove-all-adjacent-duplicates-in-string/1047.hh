#pragma once

struct Solution
{
    std::string removeDuplicates(std::string s)
    {
        std::vector<char> st;
        for (auto ch : s) {
            st.emplace_back(ch);
            auto n = st.size();
            if (n >= 2 && st[n - 1] == st[n - 2]) {
                st.pop_back();
                st.pop_back();
            }
        }
        std::string res;
        for (auto ch : st)
            res += ch;
        return res;
    }
};

