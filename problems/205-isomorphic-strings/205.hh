#include <string>
#include <unordered_map>

struct Solution
{
    bool isIsomorphic(std::string s, std::string t)
    {
        std::unordered_map<char, char> next;
        std::unordered_map<char, char> prev;
        int l0 = s.size();
        int l1 = t.size();
        if (l0 != l1)
            return false;
        for (auto i = 0; i < l0; i++) {
            if (next.count(s[i])) {
                if (next[s[i]] != t[i])
                    return false;
            } else {
                next[s[i]] = t[i];
            }
            if (prev.count(t[i])) {
                if (prev[t[i]] != s[i])
                    return false;
            } else {
                prev[t[i]] = s[i];
            }
        }
        return true;
    }
};

