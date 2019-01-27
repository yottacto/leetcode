#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

struct TimeMap
{
    std::unordered_map<std::string, std::vector<int>> times;
    std::unordered_map<std::string, std::vector<std::string>> values;

    TimeMap()
    {
    }

    void set(std::string key, std::string value, int timestamp)
    {
        times[key].emplace_back(timestamp);
        values[key].emplace_back(value);
    }

    std::string get(std::string key, int timestamp)
    {
        auto id = std::upper_bound(times[key].begin(), times[key].end(), timestamp);
        if (id == times[key].begin())
            return {};
        return values[key][id - times[key].begin() - 1];
    }
};

