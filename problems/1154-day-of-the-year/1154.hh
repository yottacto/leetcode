#include <string>
#include <sstream>
#include <vector>
#include <numeric>

struct Solution
{
    std::vector<int> month_days{
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    };

    bool is_leap_year(int year)
    {
        return ((year % 100) && !(year % 4))
            || !(year % 400);
    }

    int dayOfYear(std::string date)
    {
        std::stringstream buf{date};
        int year;
        char ch;
        int month;
        int day;
        buf >> year >> ch >> month >> ch >> day;
        if (is_leap_year(year))
            month_days[2] = 29;
        std::partial_sum(month_days.begin(), month_days.end(), month_days.begin());
        auto res = month_days[month - 1];
        res += day;
        return res;
    }
};

