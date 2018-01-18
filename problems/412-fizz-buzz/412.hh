#pragma once
#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
    std::vector<std::string> fizzBuzz(int n)
    {
        std::vector<std::string> res(n);
        auto i = 0;
        std::generate_n(res.begin(), n, [&i]() -> std::string {
            if (++i % 15 == 0) return "FizzBuzz";
            if (i % 3 == 0) return "Fizz";
            if (i % 5 == 0) return "Buzz";
            return std::to_string(i);
        });
        return res;
    }
};

