#pragma once
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <cctype>

struct Solution
{
    using value_type = std::vector<std::string>;

    int find_match(std::string const& exp, int l)
    {
        int count = 0;
        int n = exp.size();
        for (; l < n; l++)
            if (exp[l] == '{') {
                count++;
            } else if (exp[l] == '}') {
                count--;
                if (!count)
                    return l;
            }
        return -1;
    }

    value_type calc(value_type const& l, value_type const& r, int op)
    {
        value_type res;
        if (op == 1) {
            for (auto const& i : l)
                res.emplace_back(i);
            for (auto const& i : r)
                res.emplace_back(i);
        } else {
            for (auto const& i : l)
                for (auto const& j : r)
                    res.emplace_back(i + j);
        }
        std::sort(res.begin(), res.end());
        res.erase(std::unique(res.begin(), res.end()), res.end());
        return res;
    }

    // op: 0=end, 1=+, 2=*
    value_type braceExpansionII(std::string const& exp)
    {
        // std::cerr << "calc: " << exp << "\n";
        std::stack<value_type> values;
        std::stack<int> op;
        op.emplace(0);
        int n = exp.size();
        int l = 0;
        auto prev_num = false;
        for (; l < n; ) {
            if (std::isalpha(exp[l])) {
                if (prev_num)
                    op.emplace(2);
                std::string v;
                for (; l < n && std::isalpha(exp[l]); l++)
                    v += exp[l];
                values.emplace(value_type{v});
                prev_num = true;
            } else if (exp[l] == '{') {
                if (prev_num)
                    op.emplace(2);
                auto r = find_match(exp, l);
                if (l == 0 && r == n - 1) {
                    return braceExpansionII(exp.substr(1, n - 2));
                }
                auto value = braceExpansionII(exp.substr(l, r - l + 1));
                values.emplace(value);
                l = r + 1;
                prev_num = true;
            } else if (exp[l] == ',') {
                while (op.top() >= 1) {
                    auto value0 = values.top();
                    values.pop();
                    auto value1 = values.top();
                    values.pop();
                    values.emplace(calc(value1, value0, op.top()));
                    op.pop();
                }
                op.emplace(1);
                l++;
                prev_num = false;
            }
        }
        while (op.top()) {
            auto value0 = values.top();
            values.pop();
            auto value1 = values.top();
            values.pop();
            values.emplace(calc(value1, value0, op.top()));
            op.pop();
        }
        return values.top();
    }
};

