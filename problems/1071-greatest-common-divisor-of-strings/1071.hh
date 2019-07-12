#pragma once
#include <string>

struct Solution
{
    bool check(std::string const& str, int k)
    {
        int l = str.size();
        if (l % k)
            return false;
        for (auto i = 1; i < l / k; i++)
            for (auto j = 0; j < k; j++)
                if (str[j] != str[j + i * k])
                    return false;
        return true;
    }

    std::string gcdOfStrings(std::string str1, std::string str2)
    {
        int l1 = str1.size();
        int l2 = str2.size();
        auto i = std::min(l1, l2);
        for (; i >= 1; i--) {
            if (check(str1, i) && check(str2, i) && str1.substr(0, i) == str2.substr(0, i))
                break;
        }
        return str1.substr(0, i);
    }
};

