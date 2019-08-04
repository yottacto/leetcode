#include <iostream>

struct Solution
{
    int longestDecomposition(std::string text)
    {
        if (text.empty())
            return 0;
        int n = text.size();
        for (auto i = 1; i <= n / 2; i++) {
            if (text.substr(0, i) == text.substr(n - i, i))
                return longestDecomposition(text.substr(i, n - 2 * i)) + 2;
        }
        return 1;
    }
};

