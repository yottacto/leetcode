#include <vector>
#include <string>

struct Solution
{
    std::pair<int, int> coord(char a)
    {
        int n = a - 'a';
        return {n / 5, n % 5};
    }

    std::string go(int start, int end, char pos, char neg)
    {
        std::string res;
        res += start < end
            ? std::string(end - start, pos)
            : std::string(start - end, neg);
        return res;
    }

    std::string trans(char a, char b)
    {
        if (b == 'z') {
            if (a == 'z')
                return "";
            return trans(a, 'u') + "D";
        }
        auto [x1, y1] = coord(a);
        auto [x2, y2] = coord(b);
        std::string res;
        res += go(x1, x2, 'D', 'U');
        res += go(y1, y2, 'R', 'L');
        return res;
    }

    std::string alphabetBoardPath(std::string target)
    {
        auto now = 'a';
        std::string res;
        for (auto ch : target) {
            res += trans(now, ch) + '!';
            now = ch;
        }
        return res;
    }
};

