#include <string>
#include <stack>
#include <cctype>

struct Solution
{
    std::string minRemoveToMakeValid(std::string s)
    {
        std::stack<int> pos;
        auto ts = s;
        int n = s.size();
        for (auto i = 0; i < n; i++) {
            if (s[i] == '(')
                pos.emplace(i);
            else if (s[i] == ')') {
                if (!pos.empty()) {
                    ts[i] = '*';
                    ts[pos.top()] = '*';
                    pos.pop();
                }
            }
        }
        std::string res;
        for (auto i = 0; i < n; i++)
            if (std::isalpha(s[i]) || ts[i] == '*')
                res += s[i];
        return res;
    }
};

