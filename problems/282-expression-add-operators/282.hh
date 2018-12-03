#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

#include <iostream>

using ll = long long;

struct Solution
{
    std::vector<std::string> res;
    std::vector<int> pos;
    std::vector<int> op;
    int n;
    std::string num;
    ll target;

    auto get_num(std::string const& s, int& p)
    {
        auto r = std::find_if_not(s.begin() + p, s.end(), [](auto ch) {
            return std::isdigit(ch);
        }) - s.begin();
        if (r - p > 1 && s[p] == '0')
            throw "no leading zeros";
        auto res = std::stoll(s.substr(p, r - p));
        p = r;
        return res;
    }

    auto filp(std::string s)
    {
        for (auto& ch : s)
            if (ch == '+')
                ch = '-';
            else if (ch == '-')
                ch = '+';
        return s;
    }

    // [l, r)
    auto eval_impl(std::string const& s) -> ll
    {
        // std::cerr << "eval: " << s << "\n";
        int n = s.size();
        auto i = 0;
        auto res = get_num(s, i);
        while (i < n) {
            // std::cerr << "res=" << res << " i=" << i << " op=" << s[i] << "\n";
            if (s[i] == '*') {
                res *= get_num(s, ++i);
            } else if (s[i] == '+') {
                res += eval_impl(s.substr(i + 1));
                i = n;
            } else {
                res -= eval_impl(filp(s.substr(i + 1)));
                i = n;
            }
        }
        // std::cerr << "evaled " << s << "=" << res << "\n";
        return res;
    }

    auto eval(std::string const& s)
    {
        try {
            return eval_impl(s);
        } catch (...) {
        }
        return target - 1;
    }

    auto get_op(int x)
    {
        if (x == 0) return '*';
        if (x == 1) return '+';
        return '-';
    }

    auto get_str(int len)
    {
        auto res = num;
        for (auto i = len - 1; i >= 0; i--)
            res.insert(pos[i] + 1, 1, get_op(op[i]));
        return res;
    }

    void dfs(int p, int d)
    {
        if (p <= n - 1) {
            auto str = get_str(d);
            if (eval(str) == target)
                res.emplace_back(str);
            if (p == n - 1) return;
        }
        for (auto i = p; i < n - 1; i++) {
            if (i > p && num[p] == '0') break;
            pos[d] = i;
            for (auto j = 0; j < 3; j++) {
                op[d] = j;
                dfs(i + 1, d + 1);
            }
        }
    }

    auto addOperators(std::string num, ll target)
    {
        this->num = num;
        this->target = target;
        n = num.size();
        pos.resize(n);
        op.resize(n);
        dfs(0, 0);
        return res;
    }
};

