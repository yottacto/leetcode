#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>
#include <cctype>

struct token
{
    std::string raw;
    bool _is_integer{false};
    bool _is_variable{false};
    bool _is_keyword{false};

    auto get_string(std::string const& exp, int l, int r)
    {
        std::string name{};
        for (auto i = l; i < r; i++)
            if (std::isalnum(exp[i]))
                name += exp[i];
            else
                break;
        return name;
    }

    auto get_number(std::string const& exp, int l, int r)
    {
        std::string name{exp[l++]};
        for (auto i = l; i < r; i++)
            if (std::isdigit(exp[i]))
                name += exp[i];
            else
                break;
        return name;
    }


    token(std::string const& exp, int l, int r)
    {
        if (exp[l] == '(') {
            _is_keyword = true;
            raw = get_string(exp, l + 1, r);
            return;
        }
        if (exp[l] == '-' || std::isdigit(exp[l])) {
            _is_integer = true;
            raw = get_number(exp, l, r);
            return;
        }

        _is_variable = true;
        raw = get_string(exp, l, r);
        return;
    }

    auto is_integer() -> bool
    {
        return _is_integer;
    }

    auto integer() -> int
    {
        return std::stoi(raw);
    }

    auto is_variable() -> bool
    {
        return _is_variable;
    }

    auto variable() -> std::string
    {
        return raw;
    }

    auto is_add() -> bool
    {
        return _is_keyword && raw == "add";
    }

    auto is_mult() -> bool
    {
        return _is_keyword && raw == "mult";
    }

    auto is_let() -> bool
    {
        return _is_keyword && raw == "let";
    }

    auto length() -> int
    {
        return raw.size();
    }
};

struct Solution
{
    std::unordered_map<std::string, std::stack<int>> scoped_value;

    int calc(std::string exp, int l, int r)
    {
        auto t = token{exp, l, r};
        if (t.is_integer())
            return t.integer();
        if (t.is_variable()) {
            return scoped_value[t.variable()].top();
        }
        if (t.is_add()) {
            l += 5;
            auto lhs = calc_value(exp, l, r);
            auto rhs = calc_value(exp, l, r);
            return lhs + rhs;
        }
        if (t.is_mult()) {
            l += 6;
            auto lhs = calc_value(exp, l, r);
            auto rhs = calc_value(exp, l, r);
            return lhs * rhs;
        }
        if (t.is_let()) {
            std::vector<std::string> names;
            auto res = 0;
            l += 5;
            for (; ; ) {
                auto tt = token{exp, l, r};
                if (tt.is_variable()) {
                    l += tt.length() + 1;
                    if (l == r) {
                        res = scoped_value[tt.variable()].top();
                        break;
                    }
                    names.emplace_back(tt.variable());
                    auto tv = calc_value(exp, l, r);
                    scoped_value[tt.variable()].push(tv);
                } else {
                    res = calc(exp, l, r - 1);
                    break;
                }
            }
            for (auto const& name : names)
                scoped_value[name].pop();
            return res;
        }
        return -1;
    }

    auto match(std::string exp, int& l, int r) -> int
    {
        auto sum = 0;
        for (auto i = l; i < r; i++) {
            if (exp[i] == '(')
                sum++;
            else if (exp[i] == ')')
                sum--;
            if (sum == 0)
                return i + 1;
        }
        return -1;
    }

    int calc_value(std::string exp, int& l, int r)
    {
        auto t = token{exp, l, r};
        if (t.is_integer()) {
            l += t.length() + 1;
            return t.integer();
        }
        if (t.is_variable()) {
            l += t.length() + 1;
            return scoped_value[t.variable()].top();
        }
        auto tr = match(exp, l, r);
        auto tl = l;
        l = tr + 1;
        return calc(exp, tl, tr);
    }

    int evaluate(std::string expression)
    {
        return calc(expression, 0, expression.size());
    }
};

