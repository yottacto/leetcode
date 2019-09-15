#include <string>
#include <algorithm>

struct Solution
{
    int find_match(std::string const& s, int p)
    {
        int n = s.size();
        auto sum = 0;
        for (auto i = p; i < n; i++) {
            if (s[i] == '(')
                sum++;
            else if (s[i] == ')')
                sum--;
            if (!sum)
                return i;
        }
        return -1;
    }

    std::string reverseParentheses(std::string s)
    {
        // std::cerr << "~" << s << "~\n";
        if (s.empty())
            return s;
        std::string res{};
        int n = s.size();
        for (auto i = 0; i < n; i++) {
            if (s[i] != '(') {
                res += s[i];
            } else {
                auto r = find_match(s, i);
                auto ss = s.substr(i + 1, r - i - 1);
                std::reverse(ss.begin(), ss.end());
                for (auto& ch : ss)
                    if (ch == '(')
                        ch = ')';
                    else if (ch == ')')
                        ch = '(';
                res += reverseParentheses(ss);
                i = r;
            }
        }
        return res;
    }
};

