#pragma once
#include <algorithm>
#include <string>

struct Solution
{
    std::string strWithout3a3b(int a, int b)
    {
        std::string res;
        while (a > 0 && b > 0) {
            if (a > b) {
                res += "aab";
                a -= 2;
                b--;
            } else if (b > a) {
                res += "bba";
                b -= 2;
                a--;
            } else {
                res += "ba";
                b--;
                a--;
            }
        }
        res += std::string(a, 'a') + std::string(b, 'b');
        return res;
    }
};

