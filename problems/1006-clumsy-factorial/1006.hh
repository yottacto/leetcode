#pragma once

struct Solution
{
    auto calc(int& n)
    {
        auto res = n--;
        if (n >= 1)
            res *= n--;
        if (n >= 1)
            res /= n--;
        return res;
    }

    int clumsy(int n)
    {
        auto sum = calc(n);
        // std::cerr << sum << " " << n << "\n";
        for (; n >= 1; ) {
            sum += n--;
            sum -= calc(n);
            // std::cerr << sum << " " << n << "\n";
        }
        return sum;
    }
};

