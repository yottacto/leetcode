#include <vector>
#include <string>
#include <unordered_map>

struct Solution
{
    std::unordered_map<int, int> count;
    std::vector<int> res;

    void dfs(int d, int st, std::string const& q, int& sum)
    {
        if (d == (int)q.size()) {
            sum += count[st];
            return;
        }
        dfs(d + 1, st, q, sum);
        dfs(d + 1, st | (1<<(q[d] - 'a')), q, sum);
    }

    std::vector<int> findNumOfValidWords(std::vector<std::string>& words, std::vector<std::string>& puzzles)
    {
        for (auto const& s : words) {
            auto st = 0;
            for (auto ch : s)
                st |= 1 << (ch - 'a');
            count[st]++;
        }
        for (auto const& q : puzzles) {
            auto sum = 0;
            dfs(1, 1 << (q[0] - 'a'), q, sum);
            res.emplace_back(sum);
        }
        return res;
    }
};

