#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <functional>
#include <cctype>

std::unordered_map<char, std::function<int(int, int)>> calc{
    {'+', std::plus<int>{}},
    {'-', std::minus<int>{}},
    {'*', std::multiplies<int>{}},
    {'/', std::divides<int>{}},
};

struct Solution
{
    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<int> num;
        for (auto s : tokens) {
            if (s.size() == 1 && !std::isdigit(s[0])) {
                auto rhs = num.top();
                num.pop();
                auto lhs = num.top();
                num.pop();
                num.emplace(calc[s[0]](lhs, rhs));
            } else {
                num.emplace(std::stoi(s));
            }
        }
        return num.top();
    }
};

