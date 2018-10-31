#pragma once
#include <string>
#include <unordered_map>

struct Solution
{
public:
    std::string minWindow(std::string s, std::string t)
    {
        auto len = s.size() + 1;
        auto left = -1;
        auto right = 0u;
        std::unordered_map<char, int> count;

        for (auto const& ch : t)
            count[ch]++;

        auto needed = count.size();
        for (auto i = 0u; i < s.size(); i++) {
            while (needed && right < s.size()) {
                count[s[right]]--;
                if (!count[s[right]])
                    needed--;
                right++;
            }
            if (right >= s.size() && needed)
                break;
            if (right - i < len) {
                len = right - i;
                left = i;
            }
            if (!count[s[i]]) needed++;
            count[s[i]]++;
        }

        return left == -1
            ? ""
            : s.substr(left, len);
    }
};

