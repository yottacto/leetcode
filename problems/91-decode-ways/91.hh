#pragma once
#include <string>
#include <vector>

struct Solution
{

    auto check(std::string const& s)
    {
        auto num = std::stoi(s);
        return 1 <= num && num <= 26 && s[0] != '0';
    }

    int numDecodings(std::string const& s)
    {
        int n = s.size();
        std::vector<int> f(n + 1);
        f[0] = 1;
        for (auto i = 1; i <= n; i++) {
            if (s[i - 1] != '0')
                f[i] = f[i - 1];
            if (i >= 2 && check(s.substr(i - 2, 2)))
                f[i] += f[i - 2];
        }
        return f[n];
    }
};

