#pragma once
#include <string>
#include <vector>
#include <tuple>

struct Solution
{
    std::vector<int> p;

    int pow(int base, int exponent)
    {
        if (!exponent) return 1;
        auto res = pow(base, exponent/2);
        res *= res;
        if (exponent&1) res *= base;
        return res;
    }

    std::string crackSafe(int n, int k)
    {
        auto block = pow(k, n-1);
        auto tot = pow(k, n);
        p.reserve(tot);
        for (auto i = 0; i < k; i++)
            for (auto j = 0; j < block; j++)
                p.emplace_back(j * k + i);
        std::string res;
        for (auto i = 0; i < tot; i++)
            for (auto j = i; p[j] >= 0; ) {
                res += std::to_string(j / block);
                std::tie(p[j], j) = std::make_tuple(-1, p[j]);
            }
        return res + std::string(n-1, '0');
    }
};

