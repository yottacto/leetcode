#include <set>

struct Solution
{
    int numberOfDays(int y, int m)
    {
        std::set<int> m31{1, 3, 5, 7, 8, 10, 12};
        std::set<int> m30{4, 6, 9, 11};
        if (m == 2) {
            if (((y % 4) == 0 && (y % 100) != 0)
                    || ((y % 400) == 0))
                return 29;
            return 28;
        } else {
            if (m31.count(m))
                return 31;
            return 30;
        }
    }
};

