#include <string>
#include <unordered_map>
#include <stack>
#include <cctype>
#include <functional>

struct Solution
{
    std::unordered_map<char, int> priority{
        {'#', -1},
        {'!', 0},
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
    };

    std::unordered_map<char, std::function<int(int, int)>> calc{
        {'+', std::plus<int>{}},
        {'-', std::minus<int>{}},
        {'*', std::multiplies<int>{}},
        {'/', std::divides<int>{}},
    };

    int calculate(std::string s)
    {
        s = s + '!';
        std::stack<char> op;
        std::stack<int> num;
        op.emplace('#');
        int n = s.size();
        auto i = 0;
        for (; i < n; i++) {
            if (s[i] == ' ')
                continue;
            if (std::isdigit(s[i])) {
                auto tmp = 0;
                for (; i < n; i++) {
                    if (s[i] == ' ')
                        continue;
                    if (std::isdigit(s[i])) {
                        tmp = tmp * 10 + (s[i] - '0');
                    } else {
                        break;
                    }
                }
                i--;
                num.emplace(tmp);
            } else {
                while (priority[s[i]] <= priority[op.top()]) {
                    auto cur_op = op.top();
                    op.pop();
                    auto rhs = num.top();
                    num.pop();
                    auto lhs = num.top();
                    num.pop();
                    num.emplace(calc[cur_op](lhs, rhs));
                }
                op.emplace(s[i]);
            }
        }
        return num.top();
    }
};

