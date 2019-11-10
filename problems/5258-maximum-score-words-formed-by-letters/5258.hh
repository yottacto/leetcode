#include <vector>
#include <string>

struct Solution
{
    std::vector<int> score;
    std::vector<std::string> words;
    int n;

    int calc(int st, std::vector<int> count)
    {
        auto sum = 0;
        for (auto i = 0; i < n; i++)
            if ((st >> i) & 1) {
                for (auto ch : words[i]) {
                    if (!count[ch - 'a'])
                        return 0;
                    count[ch - 'a']--;
                    sum += score[ch - 'a'];
                }
            }
        return sum;
    }

    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score)
    {
        this->score = score;
        this->words = words;
        n = words.size();
        std::vector<int> count(26);
        for (auto ch : letters)
            count[ch - 'a']++;
        auto res = 0;
        for (auto st = 1; st < (1<<n); st++) {
            auto tcount = count;
            res = std::max(res, calc(st, count));
        }
        return res;
    }
};

