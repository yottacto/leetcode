#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include <iterator>
#include <random>

#include <iostream>

// // This is the Master's API interface.
// // You should not implement it, or speculate about its implementation
// struct Master
// {
//     int guess(std::string word);
// };

struct Solution
{
    auto match(std::string const& a, std::string const& b)
    {
        auto sum = 0;
        for (auto i = 0; i < 6; i++)
            sum += a[i] == b[i];
        return sum;
    }

    void findSecretWord(std::vector<std::string>& wordlist, Master& master)
    {
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::unordered_set<std::string> unguessed{wordlist.begin(), wordlist.end()};
        for (auto i = 0; i < 10; i++) {
            std::uniform_int_distribution<> dis(0, unguessed.size() - 1);
            auto it = std::next(unguessed.begin(), dis(gen));
            auto str = *it;
            auto len = master.guess(str);
            if (len == 6) break;
            unguessed.erase(it);
            for (auto it = unguessed.begin(); it != unguessed.end(); ) {
                if (match(str, *it) != len)
                    it = unguessed.erase(it);
                else
                    ++it;
            }
            // std::cout << "guessing: " << str << "\n";
            // std::cout << "matched len: " << len << "\n";
            // std::cout << "remain size: " << unguessed.size() << "\n";
        }
    }
};

