#pragma once
#include <string>
#include <cctype>
#include <numeric>
#include <map>

struct Solution
{
    using value_type = std::map<std::string, int>;

    auto to_string(value_type const& m)
    {
        return std::accumulate(m.begin(), m.end(), std::string{}, [](auto const& s, auto const& p) {
            return s + p.first + (
                p.second == 1
                    ? ""
                    : std::to_string(p.second)
            );
        });
    }

    auto match(std::string const& s, int l, int r)
    {
        auto count = 0;
        for (auto i = l; i < r; i++) {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')')
                count--;
            if (!count)
                return i;
        }
        return -1;
    }

    auto get_num(std::string const& s, int& l, int r)
    {
        auto num = 0;
        for (; l < r; l++) {
            if (!std::isdigit(s[l]))
                break;
            num = num * 10 + s[l] - '0';
        }
        return num ? num : 1;
    }

    auto get_name(std::string const& s, int& l, int r)
    {
        std::string name{s[l++]};
        for (; l < r; l++) {
            if (!std::islower(s[l]))
                break;
            name += s[l];
        }
        return name;
    }

    void merge(value_type& m1, value_type const& m2, int multiplier = 1)
    {
        for (auto const& p : m2)
            m1[p.first] += p.second * multiplier;
    }

    auto calc(std::string const& s, int l, int r) -> value_type
    {
        value_type count;
        for (; l < r; ) {
            if (s[l] == '(') {
                auto tr = match(s, l, r);
                auto tcount = calc(s, l + 1, tr);
                l = tr + 1;
                auto mul = get_num(s, l, r);
                merge(count, tcount, mul);
            } else {
                auto name = get_name(s, l, r);
                auto num = get_num(s, l, r);
                count[name] += num;
            }
        }
        return count;
    }

    auto countOfAtoms(std::string formula)
    {
        return to_string(calc(formula, 0, formula.size()));
    }
};

