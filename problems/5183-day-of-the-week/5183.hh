#include <string>
#include <vector>

struct Solution
{
    std::vector<std::string> names{
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    std::string dayOfTheWeek(int d, int m, int y)
    {
        if (m == 1 || m == 2) {
            m += 12;
            y--;
        }
        auto w = (d + 1 + 2*m + 3*(m + 1)/5 + y + y/4 - y/100 + y/400) % 7;
        return names[w];
    }
};

