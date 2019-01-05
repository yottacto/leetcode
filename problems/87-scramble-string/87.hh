#pragma once
#include <string>
#include <unordered_map>
#include <map>
#include <utility>

struct Solution
{
    using pair = std::pair<std::string, std::string>;
    std::map<pair, bool> f;

    auto equal(std::string s1, std::string s2)
    {
        if (s1.size() != s2.size())
            return false;
        std::unordered_map<char, int> um1;
        for (auto ch : s1)
            um1[ch]++;
        std::unordered_map<char, int> um2;
        for (auto ch : s2)
            um2[ch]++;
        return um1 == um2;
    }

    bool isScramble(std::string const& s1, std::string const& s2)
    {
        if (f.count({s1, s2}))
            return f.at({s1, s2});
        if (!equal(s1, s2))
            return false;
        if (s1 == s2)
            return true;
        int n = s1.size();
        for (auto i = 1; i < n; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(n - i))
                && isScramble(s1.substr(i), s2.substr(0, n - i)))
                return f[{s1, s2}] = true;
            if (isScramble(s1.substr(0, i), s2.substr(0, i))
                && isScramble(s1.substr(i), s2.substr(i)))
                return f[{s1, s2}] = true;
        }
        return f[{s1, s2}] = false;
    }
};

