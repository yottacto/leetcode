#pragma once
#include <string>

struct Solution
{
    bool isValid(std::string s)
    {
        if (s.empty())
            return true;
        auto p = s.find("abc");
        if (p == std::string::npos)
            return false;
        s.erase(p, 3);
        return isValid(s);
    }
};

