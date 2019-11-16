#include <algorithm>
#include <vector>
#include <string>

struct Solution
{
    std::string encode(int num)
    {
        if (!num)
            return {};
        int l = 1;
        for (; (1<<(l+1)) - 1 <= num; l++)
            ;
        num -= ((1<<l) - 1);
        std::vector<int> a;
        for (auto i = 0; i < l; i++) {
            a.emplace_back(num % 2);
            num /= 2;
        }
        std::string res;
        std::reverse(a.begin(), a.end());
        for (auto i : a)
            res += char('0' + i);
        return res;
    }
};

