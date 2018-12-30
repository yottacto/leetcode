#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cctype>

struct Solution
{
    std::unordered_map<std::string, std::vector<std::string>> cap;
    std::unordered_map<std::string, std::vector<std::string>> vowel;
    std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    std::unordered_set<std::string> all;

    auto to_lower(std::string s)
    {
        for (auto& ch : s)
            ch = std::tolower(ch);
        return s;
    }

    auto all_vowel(std::string s)
    {
        for (auto& ch : s) {
            ch = std::tolower(ch);
            if (vowels.count(ch))
                ch = '*';
        }
        return s;
    }

    std::vector<std::string> spellchecker(std::vector<std::string>& wordlist, std::vector<std::string>& queries)
    {
        for (auto const& s: wordlist) {
            cap[to_lower(s)].emplace_back(s);
            vowel[all_vowel(s)].emplace_back(s);
            all.emplace(s);
        }
        std::vector<std::string> res;
        for (auto const& s : queries) {
            if (all.count(s)) {
                res.emplace_back(s);
                continue;
            }
            auto ls = to_lower(s);
            if (cap.count(ls)) {
                res.emplace_back(cap[ls].front());
                continue;
            }
            auto av = all_vowel(s);
            if (vowel.count(av)) {
                res.emplace_back(vowel[av].front());
                continue;
            }
            res.emplace_back("");
        }
        return res;
    }
};

