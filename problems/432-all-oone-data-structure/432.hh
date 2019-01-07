#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

struct AllOne
{
    std::unordered_map<std::string, int> um;
    std::unordered_map<std::string, int> pos;
    std::unordered_map<int, int> first;
    std::unordered_map<int, int> last;
    std::vector<std::string> keys;

    // Inserts a new key <Key> with value 1. Or increments an existing key by 1.
    void inc(std::string key)
    {
        if (!um.count(key)) {
            um[key] = 1;
            keys.emplace_back(key);
            pos[key] = keys.size() - 1;
            last[1] = keys.size();
            if (!first.count(1))
                first[1] = keys.size() - 1;
        } else {
            auto v = ++um[key];
            pos[keys[first[v - 1]]] = pos[key];
            std::swap(keys[pos[key]], keys[first[v - 1]]);
            pos[key] = first[v - 1];
            first[v - 1]++;
            if (last[v - 1] == first[v - 1])  {
                first.erase(v - 1);
                last.erase(v - 1);
            }
            if (last.count(v)) {
                last[v]++;
            } else {
                first[v] = pos[key];
                last[v] = pos[key] + 1;
            }
        }

        print();
    }

    // Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
    void dec(std::string key)
    {
        if (!um.count(key)) return;
        auto v = --um[key];
        pos[keys[last[v + 1] - 1]] = pos[key];
        std::swap(keys[pos[key]], keys[last[v + 1] - 1]);
        pos[key] = last[v + 1] - 1;
        last[v + 1]--;
        if (last[v + 1] == first[v + 1])  {
            first.erase(v + 1);
            last.erase(v + 1);
        }
        if (!v) {
            um.erase(key);
            keys.pop_back();
            pos.erase(key);
        } else {
            if (first.count(v)) {
                first[v]--;
            } else {
                first[v] = pos[key];
                last[v] = pos[key] + 1;
            }
        }
        print();
    }

    // Returns one of the keys with maximal value.
    std::string getMaxKey()
    {
        if (keys.empty()) return {};
        return keys.front();
    }

    // Returns one of the keys with Minimal value.
    std::string getMinKey()
    {
        if (keys.empty()) return {};
        return keys.back();
    }

    void print()
    {
        return;
        if (keys.empty()) {
            std::cout << "[]\n";
            return;
        }
        for (auto const& p : um)
            std::cout << p.first << "->" << p.second << ", ";
        std::cout << "\n";
        for (auto const& key: keys)
            std::cout << key << ", ";
        std::cout << "\n";
        for (auto i = um[keys[0]]; i >= 1; i--) {
            if (!first.count(i)) continue;
            std::cout << "range[" << i << "]=[" << first[i] << "," << last[i] << ") ";
        }
        std::cout << "\n";
    }

};

