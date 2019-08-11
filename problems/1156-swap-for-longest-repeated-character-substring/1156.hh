#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

struct Solution
{
    int maxRepOpt1(std::string text)
    {
        int n = text.size();
        std::unordered_map<char, int> lmost;
        std::unordered_map<char, int> rmost;
        std::vector<int> left(n);
        std::vector<int> right(n);
        for (auto i = 0; i < n; i++) {
            left[i] = i;
            if (i && text[i - 1] == text[i])
                left[i] = left[i - 1];
            if (!lmost.count(text[i]))
                lmost[text[i]] = i;
            rmost[text[i]] = i;
        }
        for (auto i = n - 1; i >= 0; i--) {
            right[i] = i;
            if (i < n - 1 && text[i + 1] == text[i])
                right[i] = right[i + 1];
        }
        auto res = 0;
        for (auto i = 0; i < n; i++) {
            auto ch = text[i];
            auto len = i - left[i] + 1;
            if (lmost[ch] < left[i] || rmost[ch] > right[i])
                len++;
            res = std::max(res, len);

            if (i && i < n - 1 && text[i - 1] == text[i + 1] && text[i] != text[i - 1]) {
                auto ch = text[i - 1];
                auto len = i - left[i - 1] + right[i + 1] - i;
                if (lmost[ch] < left[i - 1] || rmost[ch] > right[i + 1])
                    len++;
                res = std::max(res, len);
            }
        }
        return res;
    }
};

