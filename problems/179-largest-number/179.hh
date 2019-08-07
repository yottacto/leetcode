#include <algorithm>
#include <vector>
#include <string>

struct Solution
{
    std::string largestNumber(std::vector<int>& nums)
    {
        std::vector<std::string> a;
        a.reserve(nums.size());
        for (auto i : nums)
            a.emplace_back(std::to_string(i));
        auto less = [](auto const& a, auto const& b) {
            return a + b > b + a;
        };
        std::sort(a.begin(), a.end(), less);
        std::string res;
        for (auto const& s : a)
            res += s;
        auto lead = 0u;
        for (; lead < res.size() - 1 && res[lead] == '0'; lead++)
            ;
        return res.substr(lead);
    }
};

