#include <string>
#include <algorithm>

struct Solution
{
    int maximum_representation(std::string const& s)
    {
        int len = s.size();
        auto i = 0;
        auto j = 1;
        auto k = 0;
        while (i < len && j < len && k < len) {
            int t = s[(i + k) % len] - s[(j + k) % len];
            if (!t) k++;
            else {
                if (t > 0)
                    j = j + k + 1;
                else
                    i = i + k + 1;
                if (i == j)
                    j++;
                k = 0;
            }
        }
        return std::min(i, j);
    }

    std::string lastSubstring(std::string s)
    {
        auto p = maximum_representation(s);
        return s.substr(p);
    }
};

