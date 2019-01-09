#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

struct AllOne
{
    std::unordered_map<std::string, int> id;
    std::vector<std::string> all;
    int alloc{0};

    std::unordered_map<int, int> um;
    std::unordered_map<int, int> pos;
    std::unordered_map<int, std::pair<int, int>> range;
    std::vector<int> keys;

    auto get_kid(std::string const& key)
    {
        if (!id.count(key)) {
            id[key] = alloc++;
            all.emplace_back(key);
        }
        return id[key];
    }

    // Inserts a new key <Key> with value 1. Or increments an existing key by
    // 1.
    void inc(std::string const& key)
    {
        auto kid = get_kid(key);
        if (!um.count(kid)) {
            um[kid] = 1;
            keys.emplace_back(kid);
            pos[kid] = keys.size() - 1;
            if (!range.count(1))
                range[1].first = keys.size() - 1;
            range[1].second = keys.size();
        } else {
            auto v = ++um[kid];
            pos[keys[range[v - 1].first]] = pos[kid];
            std::swap(keys[pos[kid]], keys[range[v - 1].first]);
            pos[kid] = range[v - 1].first;
            range[v - 1].first++;
            if (range[v - 1].first == range[v - 1].second)
                range.erase(v - 1);
            if (range.count(v))
                range[v].second++;
            else
                range[v] = {pos[kid], pos[kid] + 1};
        }
    }

    // Decrements an existing key by 1. If Key's value is 1, remove it from the
    // data structure.
    void dec(std::string const& key)
    {
        auto kid = get_kid(key);
        if (!um.count(kid)) return;
        auto v = --um[kid];
        pos[keys[range[v + 1].second - 1]] = pos[kid];
        std::swap(keys[pos[kid]], keys[range[v + 1].second - 1]);
        pos[kid] = range[v + 1].second - 1;
        range[v + 1].second--;
        if (range[v + 1].first == range[v + 1].second)
            range.erase(v + 1);
        if (!v) {
            um.erase(kid);
            keys.pop_back();
            pos.erase(kid);
        } else {
            if (range.count(v))
                range[v].first--;
            else
                range[v] = {pos[kid], pos[kid] + 1};
        }
    }

    // Returns one of the keys with maximal value.
    std::string getMaxKey()
    {
        if (keys.empty()) return {};
        return all[keys.front()];
    }

    // Returns one of the keys with Minimal value.
    std::string getMinKey()
    {
        if (keys.empty()) return {};
        return all[keys.back()];
    }
};

