#include <string>
#include <vector>

struct Solution
{
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        std::vector<int> count(26);
        for (auto ch : magazine)
            count[ch - 'a']++;
        for (auto ch : ransomNote)
            if (!count[ch - 'a'])
                return false;
            else
                count[ch - 'a']--;
        return true;
    }
};

