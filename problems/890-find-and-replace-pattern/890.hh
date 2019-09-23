#include <vector>
#include <string>

struct Solution
{
    std::vector<char> forward;
    std::vector<char> backward;

    bool check(std::string const& word, std::string const& pattern)
    {
        if (word.size() != pattern.size())
            return false;
        int n = word.size();
        forward.clear();
        backward.clear();
        forward.resize(26);
        backward.resize(26);
        for (auto i = 0; i < n; i++) {
            int t0 = word[i] - 'a';
            int t1 = pattern[i] - 'a';
            if (forward[t0]) {
                if (forward[t0] != pattern[i])
                    return false;
            } else {
                forward[t0] = pattern[i];
            }

            if (backward[t1]) {
                if (backward[t1] != word[i])
                    return false;
            } else {
                backward[t1] = word[i];
            }
        }
        return true;
    }

    std::vector<std::string> findAndReplacePattern(
        std::vector<std::string>& words,
        std::string pattern
    )
    {
        std::vector<std::string> res;
        for (auto const& word : words)
            if (check(word, pattern))
                res.emplace_back(word);
        return res;
    }
};

