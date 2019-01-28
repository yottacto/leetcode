#pragma once
#include <algorithm>
#include <list>
#include <iterator>
#include <unordered_map>
#include <utility>

struct LFUCache
{
    using iter_type = std::list<int>::iterator;

    // key -> {value, freq}
    std::unordered_map<int, std::pair<int, int>> data;
    // key -> iter
    std::unordered_map<int, iter_type> pos;
    // freq -> list<key>
    std::unordered_map<int, std::list<int>> list;
    int min;
    int capacity;

    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        if (!data.count(key))
            return -1;
        auto freq = ++data[key].second;
        list[freq].emplace_back(key);
        list[freq - 1].erase(pos[key]);
        pos[key] = std::prev(list[freq].end());
        if (freq - 1 == min && list[freq - 1].empty())
            min++;
        return data[key].first;
    }

    void put(int key, int value)
    {
        if (capacity <= 0)
            return;
        if (data.count(key)) {
            data[key].first = value;
            get(key);
            return;
        }
        if ((int)data.size() == capacity) {
            auto evict = list[min].front();
            list[min].pop_front();
            data.erase(evict);
            pos.erase(evict);
        }
        data[key] = {value, 1};
        list[1].emplace_back(key);
        pos[key] = std::prev(list[1].end());
        min = 1;
    }
};

