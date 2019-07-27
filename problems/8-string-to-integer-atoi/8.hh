#include <string>
#include <limits>
#include <cctype>

auto max_int = std::numeric_limits<int>::max();
auto min_int = std::numeric_limits<int>::min();

struct Solution
{
    int myAtoi(std::string str)
    {
        int n = str.size();
        auto op = 1ll;
        auto sum = 0ll;
        auto i = 0;
        for (; i < n && str[i] == ' '; )
            i++;
        if (i == n)
            return 0;
        if (str[i] == '+' || str[i] == '-') {
            if (str[i] == '-')
                op = -1;
            i++;
        }
        if (i == n || !std::isdigit(str[i]))
            return 0;
        for (; i < n && std::isdigit(str[i]); i++) {
            long long t = str[i] - '0';
            auto res = op * (sum * 10 + t);
            if (static_cast<int>(res) != res)
                return op == 1 ? max_int : min_int;
            sum = sum * 10 + t;
        }
        return op * sum;
    }
};

