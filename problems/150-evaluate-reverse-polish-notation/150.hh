#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <functional>

std::unordered_map<std::string, std::function<int(int, int)>> calc{
    {"+", std::plus<int>{}},
    {"-", std::minus<int>{}},
    {"*", std::multiplies<int>{}},
    {"/", std::divides<int>{}},
};

struct Solution
{
    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<int> num;
        for (auto const& s : tokens) {
            auto const& it = calc.find(s);
            if (it != calc.end()) {
                auto rhs = num.top();
                num.pop();
                auto lhs = num.top();
                num.pop();
                num.emplace(it->second(lhs, rhs));
            } else {
                num.emplace(std::stoi(s));
            }
        }
        return num.top();
    }
};

