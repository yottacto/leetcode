#pragma once
#include <string>

struct Solution
{
    std::string defangIPaddr(std::string address)
    {
        std::string res;
        for (auto ch : address) {
            if (ch != '.')
                res += ch;
            else
                res += "[.]";
        }
        return res;
    }
};

